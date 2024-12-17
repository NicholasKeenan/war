#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"

//fucntion to shuffle deck
void shuffleDeck ( CARD deck[] ) {
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
}

void playRound ( PLAYER *player1, PLAYER *player2, int *roundCounter ) {
    
    int player1Wins = 0;
    int player2Wins = 0;

    CARD card1 = player1->hand[*roundCounter];
    CARD card2 = player2->hand[*roundCounter];

    //displays what each player plays
    printf ( "\nYou play: %s of %s\n", card1.card, card1.suit );
    printf ( "Computer plays: %s of %s\n", card2.card, card2.suit );

    int result = compareCards ( &card1, &card2 ); //compares cards played

    if ( result > 0 ) {

        printf ( "\nYou Won the Round!\n" ); //declares winner

        player1Wins++; //adds to the win counter of player 1

        player1->hand[ player1->handSize ] = card1; //player 1 gets their card back
        player1->hand[ player1->handSize + 1 ] = card2; //player 1 gets the other players card
        player1->handSize += 2;


        //removes winning card and other players card so they are at the back of the deck
        //makes next card in deck the new top card
        for ( int i = *roundCounter; i < player1->handSize - 2; i++ ) {

            player1->hand[i] = player1->hand[ i + 2 ]; //shift player 1's cards

        }

        for ( int i = *roundCounter; i < player2->handSize - 1; i++ ) {

            player2->hand[i] = player2->hand[ i + 1 ]; //shift player 2's cards

        }

    } else if ( result < 0 ) {

        printf ( "\nComputer Wins the Round!\n" );//declares winner

        player2Wins++; //adds to the win counter of player 2

        player2->hand[ player2->handSize ] = card2; //player 2 gets their card back
        player2->hand[ player2->handSize + 1 ] = card1; //player 2 gets the other players card
        player2->handSize += 2;

        //removes winning card and other players card so they are at the back of the deck
        //makes next card in deck the new top card
        for ( int i = *roundCounter; i < player1->handSize - 1; i++ ) {

            player1->hand[i] = player1->hand[ i + 1 ]; //shift player 1's cards

        }

        for ( int i = *roundCounter; i < player2->handSize - 1; i++ ) {

            player2->hand[i] = player2->hand[ i + 2 ]; //shift player 2's cards

        }

    } else {
        printf ( "It's a Tie!\n" );//declares winner
    }

    printf ( "\nYou Have %d Cards Left.\n", player1->handSize );
    printf ( "\nThe Computer Has %d Cards Left.\n", player2->handSize );

    ( *roundCounter )++;

}