#ifndef CARD_MANIP_H
#define CARD_MANIP_H

typedef struct { //CARD struct declaration
    char suit[16]; //suit of the card
    char card[16]; //the card itself ( "ace", "king", "two", etc. )
    int value; //value of the card ( "two" = 2, etc )
}CARD;


#endif