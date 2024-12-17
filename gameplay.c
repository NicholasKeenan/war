#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"

void playGame ( char *filename ) {

    int cardArraySize = 52; // Card array variable
    int roundCounter = 0; //round counter variable
    char userInput = NULL; //stores user input for getting instructions or starting round

    PLAYER player1, player2; //creates players

    CARD *cardArray = readCardFile ( argv[1], &cardArraySize ); //brings file into main
    if ( cardArray == NULL ) return 0; //deals with errors reading file

    shuffleDeck ( cardArray ); //shuffles deck
    dealCards ( cardArray, &player1, &player2 ); //deals each player their cards

    while ( player1.handSize > 0 && player2.handSize > 0 ) { //plays rounds until one player has 0 cards left

        playRound ( &player1, &player2, &roundCounter );

    }

    if ( player1.handSize > 0 ) { //determines game winner
        printf ( "You Win This Game!\n" );
    } else {
        printf ( "You Lose... Computer Win This Game!\n" );
    }

}