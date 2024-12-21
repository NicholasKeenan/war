//STRINGMANIP FILE
//Does any kind of string manipulation like trimming, cutting, or changing text color

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "stringManip.h"

//function to trim space from front and back of string, assigns the leading and trailing space to a variable
//the string being trimmed is passed in
char* str_trim ( char* s ) { // Trim function

    if ( s == NULL || *s == '\0' ) return NULL;

    while ( isspace ( *s ) ) s++; // Looks at beginning

    char *end = s + strlen ( s ) - 1; // Pointer to end

    while ( isspace ( *end ) ) end--; // Trims trailing space

    *( end + 1 ) = 0; // Sets new NULL terminator

    return s;

}

//function to cut the leading and trailing space in a string
//the string being cut, and the variables containing the leading and trailing white space are passed in
char *str_cut ( char* s, int start, int end ) { // Cut function

    s += start;

    char buffer[2048];
    strncpy ( buffer, s, end - start );

    return buffer;

}

//function to turn text green
void greenText() {
    printf ( "\033[0;32m" );
}

//function to turn text red
void redText() {
    printf ( "\033[1;31m" );
}

//function to set the text color back to white
void resetText_Color() {
    printf ( "\033[0m" );
}