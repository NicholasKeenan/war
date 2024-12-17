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
    
    CARD card1 = player1->hand[*roundCounter];
    CARD card2 = player2->hand[*roundCounter];

    //displays what each player plays
    printf ( "You play: %s of %s\n", card1.card, card1.suit );
    printf ( "Computer plays: %s of %s\n", card1.card, card1.suit );

    int result = compareCards ( &card1, &card2 ); //compares cards played

    if ( result > 0 ) {

        printf ( "You Won the Round!\n" ); //declares winner

        player1->hand[ 26 + *roundCounter ] = card1; //player 1 gets their card back
        player1->hand[ 26 + *roundCounter + 1 ] = card2; //player 1 gets the other players card

        //removes winning card and other players card so they are at the back of the deck
        //makes next card in deck the new top card
        for ( int i = *roundCounter; i < 25; i++ ) {

            player1->hand[i] = player1->hand[ i + 1 ];
            player2->hand[i] = player2->hand[ i + 1 ];

        }

    } else if ( result < 0 ) {

        printf ( "Computer Wins the Round!\n" );//declares winner

        player2->hand[ 26 + *roundCounter ] = card2; //player 1 gets their card back
        player2->hand[ 26 + *roundCounter + 1 ] = card1; //player 1 gets the other players card back

        //removes winning card and other players card so they are at the back of the deck
        //makes next card in deck the new top card
        for ( int i = *roundCounter; i < 25; i++ ) {

            player1->hand[i] = player1->hand[ i + 1 ];
            player2->hand[i] = player2->hand[ i + 1 ];

        }

    } else {
        printf ( "It's a Tie!\n" );//declares winner
    }

    ( *roundCounter )++;

}