#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"

int main ( int argc, char *argv[] ) {
    
    int cardArraySize = 52; // Card array variable

    CARD *cardArray = readCardFile ( argv[1], &cardArraySize ); //brings file into main

    if ( cardArray == NULL ) return 0;

    printCard ( cardArray, cardArraySize );

}