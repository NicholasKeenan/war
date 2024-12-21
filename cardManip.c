//CARDMANIP FILE
//deals with reading the card file, sending the data to be trimmed, storing the
//data, printing each card, and comparing the values of the cards.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cardManip.h"
#include "stringManip.h"

// Function to read room, the name of the file, and the pointer for the size of the card array is passed in
CARD* readCardFile ( char* filename, int *cardArraySize ) { 

    FILE *file = fopen ( filename, "r" ); // Opens file as read

    if ( file == NULL ) { // Checks if file can be read
        perror ( "Couldn't Open File\n" ); // Error message if not possible
        return NULL;
    }

    int cArraySize = 52; // size of array

    CARD *cardArray = malloc ( sizeof ( CARD ) * cArraySize ); // Allocates memory for the array of cards
    if (cardArray == NULL) { //checks memory allocated successfully
        perror("Memory allocation failed for card array");
        return NULL;
    }

    char line[2048]; // Character buffer to store each line
    int cardIndex = 0; // Start of the list of cards 

    while ( fgets ( line, sizeof ( line ), file ) != NULL ) { //copies data

        if ( strncmp ( line, "Suit:", 5 ) == 0 ) { // Checks if line says the suit of the card

            strcpy ( cardArray[cardIndex].suit, str_trim ( line + 5 ) ); //copies suit data to structure

        }

        else if ( strncmp ( line, "Card:", 5 ) == 0 ) { // Checks if line says the card

            strcpy ( cardArray[cardIndex].card, str_trim ( line + 5 ) ); //copies card data to structure

        }

        else if ( strncmp ( line, "Value:", 6 ) == 0 ) { // Checks if line says the card
            cardArray[cardIndex].value = atoi(str_trim(line + 6)); // Assign integer value
            cardIndex++; // Accesses next index in deck
        }

    }

    *cardArraySize = cardIndex + 1;

    return cardArray; // Returns pointer

}

//function to print the cards, the pointer for the card array and the size of the array are passed in
void printCard ( CARD *cardArray, int arraySize ) { // Prints cards

    for ( int i = 0; i < arraySize; i++ ) {
        printf ( "%s of %s\n\n VALUE: %d\n", cardArray[i].card, cardArray[i].suit, cardArray[i].value );
    }

}

//function to compare cards, the pointers to the first card in both players hands are passed in
int compareCards ( CARD *card1, CARD *card2 ) { // compares cards
    return card1->value - card2->value; //returns positive if card1>card2, negative if card2>card1, and 0 if equal
}