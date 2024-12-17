#ifndef CARD_MANIP_H
#define CARD_MANIP_H

typedef struct { //CARD struct declaration
    char suit[16]; //suit of the card
    char card[16]; //the card itself ( "ace", "king", "two", etc. )
    int value[16]; //value of the card ( "two" = 2, etc )
}CARD;

typedef struct {
    CARD hand[26];
    int handSize;
} PLAYER;

CARD* readCardFile ( char* filename, int *cardArraySize );
void printCard ( CARD *cardArray, int arraySize );
int compareCards ( CARD *card1, CARD *card2 );

#endif