#ifndef DECK_MANIP_H
#define DECK_MANIP_H

void shuffleDeck ( CARD deck[] );
void dealCards ( CARD deck[], PLAYER *player1, PLAYER *player2 );
void playRound ( PLAYER *player1, PLAYER *player2, int *roundCounter );
void freeMemory ( PLAYER *player1, PLAYER *player2, CARD *cardArray );

#endif