//MAIN FUNCTION
//PLAYS THE GAME

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"

//main function that runs the game loop
//an argument counter and an array of arguments to be passed into the program are passed in
int main ( int argc, char *argv[] ) {

    char choice; //stores user input for instructions vs starting
    int cardArraySize = 52; // Card array variable
    int roundCounter = 0; //round counter variable

    PLAYER player1, player2; //creates players

    CARD *cardArray = readCardFile ( argv[1], &cardArraySize ); //brings file into main
    if ( cardArray == NULL ) return 0; //deals with errors reading file


    //STARTUP PROCEDURE
    do {
        resetText_Color();

        while ( choice != '\n' && choice != '1' ) {

            greenText(); //makes text green

            //Displays instructions to player on how to start or see rules of the game
            printf ( "\nHello, Welcome!\n\nTo recieve instructions and begin the game... Just Press Enter on Your Keyboard\n\nTo Get the Rules of The Game... Just Press 1 On Your Keyboard\n" );
            choice = getchar(); //collects user input
            if ( choice == '\n' ) {//starts game if player presses enter
                
                printf ( "\nGreat! Let's begin.\nTo Start Each Round As Well As This One, Just Press 'ENTER' On Your Keyboard!\n\n" );

                while ( choice != '\n' ) { //gets new choice

                    printf ( "Please Press 'ENTER' To Begin:\n" );
                    choice = getchar();
                }

                resetText_Color(); //sets text color back to white

            } else if ( choice == '1' ) { //prints instructions, rules of the game, and controls if user enters 1

                choice = '\0'; //resets choice

                //prints the game mechanics/rules of war
                printf ( "\nHere Are The Rules of War!\nIf At Any Time You Would Like to Start The Game, Just Press Enter on Your Keyboard.\n\n1. The deck of cards is shuffled and each player is dealt half of the total cards (26)\n\n2. Each round the players will each set down their top card to face off.\n\n3. Those cards will then be compared... The one with the highest value wins the round.\n\n4. The winner of each round will recieve the losing players card and keep their own.\n\n5. This will continue until one player has lost all of their cards and the winner will be the other player.\n\n\n" );
                printf ( "Controls:\nTo end each round as well as start the next one, just press 'ENTER' on your keyboard.\n\n" );

                while ( choice != '\n' ) { //gets new choice

                    printf ( "Please Press 'ENTER' To Begin:\n" );
                    choice = getchar();
                }

                resetText_Color(); //sets text color back to white

                break; //exits loop

            } else {
                
                while ( choice != '\n' && choice != '1' ) { //checks if invalid choice has been changed
                    choice = '\0'; //resets choice
                    redText();
                    printf ( "\nInvalid Choice, Enter 'ENTER' or '1'.\n" ); //tells user that the choice is invalid
                    choice = getchar();
                    resetText_Color();
                }

            }
            resetText_Color();
        }

        shuffleDeck ( cardArray ); //shuffles deck
        dealCards ( cardArray, &player1, &player2 ); //deals each player their cards

        while ( player1.handSize > 0 && player2.handSize > 0 ) { //plays rounds until one player has 0 cards left

            greenText(); //sets text to green
            printf ( "-----------------------------------------------------\n" ); //separates rounds
            resetText_Color(); //resets color to white
            
            playRound ( &player1, &player2, &roundCounter );//plays round

            if ( getchar() == 's' ){
                break;
            }

            while ( getchar() != '\n' ) {//waits for new input
            }//loop will keep running until user presses enter
            
        }

        if ( player1.handSize > 0 ) { //determines if game winner is the player
            printf ( "You Win This Game!\n" );
        } else if ( player2.handSize > 0 ) {
            printf ( "You Lose... Computer Win This Game!\n" ); //determines if the game winner is the player
        } else {
            printf ( "error" ); //prints an error if neither
        }

        free ( cardArray );

        printf ( "\nWould You Like to Play Again? (y/n):\n" ); //prompt to play again
        choice = getchar(); //stores input
        while ( getchar() != '\n' ) {} //clears input

        if ( choice == 'n' || choice == 'N' ) {
            printf ( "\nThanks for playing!\n" );
            break; // exits the loop and ends the game
        } else if ( choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' ) {
            // If the input is not 'y' or 'n', ask again
            while ( choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' ) {
                redText();
                printf ( "\nInvalid input. Please enter 'y' to play again or 'n' to exit: \n" );
                resetText_Color();
                choice = getchar();
                while (getchar() != '\n') {} // clears the input buffer
            }
        }

    } while ( choice == 'y' || choice == 'Y' ); //restarts program if the user wants to
    
    return 0;
    
}