#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"

int main ( int argc, char *argv[] ) {
    
    int cardArraySize = 52; // Card array variable

    CARD *cardArray = readCardFile ( argv[1], &cardArraySize ); //brings file into main

    if ( cardArray == NULL ) return 0; //deals with errors reading file

    shuffleDeck ( cardArray ); //shuffles deck

    PLAYER player1, player2; //creates players

    dealCards ( cardArray, &player1, &player2 ); //deals each player their cards

    printCard ( cardArray, cardArraySize );

}