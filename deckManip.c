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

    printf ( "Player 1 plays: %s of %s\n", card1.card, card1.suit );
    printf ( "Player 1 plays: %s of %s\n", card1.card, card1.suit );

    int result = compareCards ( &card1, &card2 );

    if ( result > 0 ) {
        printf ( "You Won the Round!\n" );
    } else if ( result < 0 ) {
        printf ( "Computer Wins the Round!\n" );
    } else {
        printf ( "It's a Tie!\n" )
    }

    ( *roundCounter )++;

}