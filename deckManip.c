#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"

//fucntion to shuffle deck
void shuffleDeck ( CARD deck[] ) {
    srand ( time ( NULL ) );
    for ( int i = 0; i < 52; i++ ) {
        int j = rand() % 52;
        CARD temp = deck[i];
        deck[i] = deck [j];
        deck [j] = temp;
    }
}

void dealCards ( CARD deck[], PLAYER *player1, PLAYER *player2 ) {
    for ( int i = 0; i < 26; i++ ) {
        player1->hand[i] = deck[i]; //deals first player 26 cards
        player2->hand[i] = deck[i+26]; //deals second player the rest of cards
    }
    player1->handSize = 26; //creates hand size for player
    player2->handSize = 26; //creates hand size for player
}

void playRound ( PLAYER *player1, PLAYER *player2, int *roundCounter ) {
    
    int player1Wins = 0;
    int player2Wins = 0;

    int roundIndex = *roundCounter; // This will point to the index of the card being played this round


    CARD card1 = player1->hand[roundIndex];
    CARD card2 = player2->hand[roundIndex];

    //displays what each player plays
    printf ( "\nYou play: %s of %s\n", card1.card, card1.suit );
    printf ( "Computer plays: %s of %s\n", card2.card, card2.suit );

    int result = compareCards ( &card1, &card2 ); //compares cards played

    if ( result > 0 ) {

        printf ( "\nYou Won the Round!\n" ); //declares winner

        player1Wins++; //adds to the win counter of player 1

        player1->hand[ player1->handSize ] = card1; //player 1 gets their card back
        player1->hand[ player1->handSize + 1 ] = card2; //player 1 gets the other players card
        player1->handSize += 1; //increase player 1's hand size

        for (int i = roundIndex; i < player1->handSize - 2; i++) {
            player1->hand[i] = player1->hand[i + 2];  // Shift player 1's cards
        }
        for (int i = roundIndex; i < player2->handSize - 1; i++) {
            player2->hand[i] = player2->hand[i + 1];  // Shift player 2's cards
        }

        player2->handSize--; //player 2 loses a card

    } else if ( result < 0 ) {

        printf ( "\nComputer Wins the Round!\n" );//declares winner

        player2Wins++; //adds to the win counter of player 2

        player2->hand[ player2->handSize ] = card2; //player 2 gets their card back
        player2->hand[ player2->handSize + 1 ] = card1; //player 2 gets the other players card
        player2->handSize += 1;

        for (int i = roundIndex; i < player1->handSize - 1; i++) {
            player1->hand[i] = player1->hand[i + 1];  // Shift player 1's cards
        }
        for (int i = roundIndex; i < player2->handSize - 2; i++) {
            player2->hand[i] = player2->hand[i + 2];  // Shift player 2's cards
        }

        player1->handSize--; //player 1 loses a card

    } else {
        printf ( "It's a Tie!\n" );//declares winner
    }


    printf ( "\nYou Have %d Cards Left.\n", player1->handSize );
    printf ( "\nThe Computer Has %d Cards Left.\n", player2->handSize );

    ( *roundCounter )++;

}