#ifndef CARD_MANIP_H
#define CARD_MANIP_H

typedef struct { //CARD struct declaration
    char suit[2048]; //suit of the card
    char card[2048]; //the card itself ( "ace", "king", "two", etc. )
    int value; //value of the card ( "two" = 2, etc )
}CARD;

typedef struct {
    CARD *hand;
    int handSize;
} PLAYER;

CARD* readCardFile ( char* filename, int *cardArraySize );
void printCard ( CARD *cardArray, int arraySize );
int compareCards ( CARD *card1, CARD *card2 );

#endif