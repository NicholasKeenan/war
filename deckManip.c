//DECKMANIP FILE
//This file does all the manipulation of decks/hands
//shuffles decks, deals hands, and plays each round

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"

//fucntion to shuffle deck, a deck (array of cards) is sent to it
void shuffleDeck ( CARD deck[] ) {
    srand ( time ( NULL ) ); //creates seed
    for ( int i = 0; i < 52; i++ ) {
        int j = rand() % 52; //gets random number out of 52
        CARD temp = deck[i];
        deck[i] = deck [j];
        deck [j] = temp;
    }
}

//function to deal cards, a deck (array of cards) and the pointers to both players is sent to it
void dealCards ( CARD deck[], PLAYER *player1, PLAYER *player2 ) {

    player1->hand = ( CARD * ) malloc( 26 * sizeof ( CARD ) );
    player2->hand = ( CARD *) malloc ( 26 * sizeof ( CARD ) );

    for ( int i = 0; i < 26; i++ ) {
        player1->hand[i] = deck[i]; //deals first player 26 cards
        player2->hand[i] = deck[i+26]; //deals second player the rest of cards
    }
    player1->handSize = 26; //creates hand size for player
    player2->handSize = 26; //creates hand size for player
}


//function to play each round, the pointers to both players and the roundCounter pointer are sent to it
void playRound ( PLAYER *player1, PLAYER *player2, int *roundCounter ) {
    
    int player1Wins = 0;
    int player2Wins = 0;

    CARD card1 = player1->hand[0];
    CARD card2 = player2->hand[0];

    printf("\nRound: %d\n", *roundCounter);

    //displays what each player plays
    printf ( "\nYou play: %s of %s\n", card1.card, card1.suit );
    printf ( "Computer plays: %s of %s\n", card2.card, card2.suit );

    int result = compareCards ( &card1, &card2 ); //compares cards played

    if ( result > 0 ) {

        printf ( "\nYou Won the Round!\n" ); //declares winner

        player1Wins++; //adds to the win counter of player 1

        player1->handSize += 2;
        player1->hand = realloc ( player1->hand, player1->handSize * sizeof ( CARD ) );

        player1->hand[player1->handSize - 2] = card1;
        player1->hand[player1->handSize - 1] = card2;

        for (int i = 0; i < player1->handSize - 1; i++) {
            player1->hand[i] = player1->hand[i + 1];  // Shift player 1's cards
        }
        for (int i = 0; i < player2->handSize - 1; i++) {
            player2->hand[i] = player2->hand[i + 1];  // Shift player 2's cards
        }

        //decrease hand for both players
        player1->handSize--;
        player2->handSize--; 

    } else if ( result < 0 ) {

        printf ( "\nComputer Wins the Round!\n" );//declares winner

        player2Wins++; //adds to the win counter of player 2

        player2->handSize += 2;
        player2->hand = realloc ( player2->hand, player2->handSize * sizeof ( CARD ) );

        player2->hand[player2->handSize - 2] = card2;
        player2->hand[player2->handSize - 1] = card1;

        for (int i = 0; i < player1->handSize - 1; i++) {
            player1->hand[i] = player1->hand[i + 1];  // Shift player 1's cards
        }
        for (int i = 0; i < player2->handSize - 1; i++) {
            player2->hand[i] = player2->hand[i + 1];  // Shift player 2's cards
        }

        //decrease hand for both players
        player1->handSize--;
        player2->handSize--;

    } else {
        printf ( "\nIt's a Tie!\n" );//declares winner

        // Move the top card of player 1 to the back of their hand
        CARD tempCard1 = card1;  // Store top card temporarily
        for (int i = 0; i < player1->handSize - 1; i++) {
            player1->hand[i] = player1->hand[i + 1];  // Shift player 1's cards
        }
        player1->hand[player1->handSize - 1] = tempCard1;  // Place the top card at the end of the hand

        // Move the top card of player 2 to the back of their hand
        CARD tempCard2 = card2;  // Store top card temporarily
        for (int i = 0; i < player2->handSize - 1; i++) {
            player2->hand[i] = player2->hand[i + 1];  // Shift player 2's cards
        }
        player2->hand[player2->handSize - 1] = tempCard2;  // Place the top card at the end of the hand
    }

    printf ( "\nYou Have %d Cards Left.\n", player1->handSize );
    printf ( "\nThe Computer Has %d Cards Left.\n", player2->handSize );

    ( *roundCounter )++;

}

//function to free all the memory, both players and the card array are passed in to be freed
void freeMemory ( PLAYER *player1, PLAYER *player2, CARD *cardArray ) {
    free ( player1->hand ); //frees player 1's hand

    free ( player2->hand ); //frees player 2's hand

    free ( cardArray ); //frees card array
}