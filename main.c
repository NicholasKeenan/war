#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cardManip.h"
#include "stringManip.h"
#include "deckManip.h"
#include "gameplay.h"

int main ( int argc, char *argv[] ) {

    char choice; //stores user input for instructions vs starting
    int playAgain = 1; //stores input for whether player wants to go again

    //STARTUP PROCEDURE

    while (playAgain) {

        while ( choice != '\n' && choice != '1' ) {

            greenText(); //makes text green

            //Displays instructions to player on how to start or see rules of the game
            printf ( "\nHello, Welcome!\n\nTo recieve instructions and begin the game... Just Press Enter on Your Keyboard\n\nTo Get the Rules of The Game... Just Press 1 On Your Keyboard\n" );
            choice = getchar(); //collects user input
            if ( choice == '\n' ) {//starts game if player presses enter
                
                printf ( "\nGreat! Let's begin.\nTo Start Each Round As Well As This One, Just Press 'ENTER' On Your Keyboard!\n\n" );

                choice = '\0'; //resets choice

                while ( choice != '\n' ) { //gets new choice

                    printf ( "Please Press 'ENTER' To Begin:\n" );
                    choice = getchar();

                }

                resetText_Color(); //sets text color back to white

                break; //exits while loop

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
                }

            }
            resetText_Color();
        }

        char playAgainInput;//variable to play again

        playGame ( argv[1] ); //plays game

        //Loops game

        while (1) {
            printf ( "\nWould You Like to Play Again? (y/n):\n" ); //asks if player wants to go again
            playAgainInput = getchar();

            switch ( playAgainInput ) {

                case 'Y':
                case 'y':
                    playAgain = 1; //continues loop
                    break;

                case 'N':
                case 'n':
                    printf ( "Okay! Thanks for Playing!\n" );
                    playAgain = 0; //exits game loop
                    break;

                default: 
                    printf ( "Invalid Input! Please Type 'y' or 'n'\n" );
                    continue;
            }

            if ( playAgain == 0 || playAgain == 1 ) { //exits loop if valid input
                break;
            }

        }

    }

    return 0;

}