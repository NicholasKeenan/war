#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "stringManip.h"

char* str_trim ( char* s ) { // Trim function

    if ( s == NULL || *s == '\0' ) return NULL;

    while ( isspace ( *s ) ) { // Looks at beginning
        s++;
    }

    char *end = s + strlen ( s ) - 1; // Pointer to end

    while ( isspace ( *end ) ) { // Trims trailing space
        end--;
    }

    *( end + 1 ) = 0; // Sets new NULL terminator

    return s;

}