#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "stringManip.h"

char* str_trim ( char* s ) { // Trim function

    if ( s == NULL || *s == '\0' ) return NULL;

    while ( isspace ( *s ) ) s++; // Looks at beginning

    char *end = s + strlen ( s ) - 1; // Pointer to end

    while ( isspace ( *end ) ) end--; // Trims trailing space

    *( end + 1 ) = 0; // Sets new NULL terminator

    return s;

}

char *str_cut ( char* s, int start, int end ) { // Cut function

    s += start;

    char buffer[2048];
    strncpy ( buffer, s, end - start );

    return buffer;

}

void greenText() {
    printf ( "\033[0;32m" );
}

void redText() {
    printf ( "\033[1;31m" );
}

void resetText_Color() {
    printf ( "\033[0m" );
}