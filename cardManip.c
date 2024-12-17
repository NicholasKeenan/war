#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cardManip.h"
#include "stringManip.h"

CARD* readCardFile ( char* filename, int *cardArraySize ) { // Function to read room file

    FILE *file = fopen ( filename, "r" ); // Opens file as read

    if ( file == NULL ) { // Checks if file can be read
        perror ( "Couldn't Open File\n" ); // Error message if not possible
        return NULL;
    }

    int cArraySize = 52; // size of array

    CARD *cardArray = malloc ( sizeof ( CARD ) * cArraySize ); // Allocates memory for the array of cards

    char line[2048]; // Character buffer to store each line
    int cardIndex = -1; // Start of the list of cards 

    while ( fgets ( line, sizeof ( line ), file ) != NULL ) { //copies data

        if ( strncmp ( line, "Suit:", 5 ) == 0 ) { // Checks if line says the suit of the card

            cardIndex++; // Accesses next index in deck

            strcpy ( cardArray[cardIndex].suit, str_trim ( line + 5 ) ); //copies suit data to structure

        }

        else if ( strncmp ( line, "Card:", 5 ) == 0 ) { // Checks if line says the card

            strcpy ( cardArray[cardIndex].card, str_trim ( line + 5 ) ); //copies card data to structure

        }

        else if ( strncmp ( line, "Value:", 6 ) == 0 ) { // Checks if line says the card

            strcpy ( cardArray[cardIndex].value, str_trim ( line + 6 ) ); //copies card value data to structure

            while ( fgets ( line, sizeof ( line ), file ) && strcmp ( str_trim ( line ), "" ) != 0 ) { // Checks if file is done 
                strcat ( cardArray[cardIndex].value, " " ); //copies spaces/new lines
                strcat ( cardArray[cardIndex].value, str_trim ( line ) );
                printf("Current value: %s\n", cardArray[cardIndex].value);
            }

        }

    }

    *cardArraySize = cardIndex + 1;

    return cardArray; // Returns pointer

}

void printCard ( CARD *cardArray, int arraySize ) { // Prints cards

    for ( int i = 0; i < arraySize; i++ ) {
        printf ( "%s of %s\n", cardArray[i].card, cardArray[i].suit );
    }

}

int compareCards ( CARD *card1, CARD *card2 ) { // compares cards
    return card1->value - card2->value; //returns positive if card1>card2, negative if card2>card1, and 0 if equal
}