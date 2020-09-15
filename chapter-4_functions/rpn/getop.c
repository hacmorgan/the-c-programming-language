#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static int buff = EOF;

int getch( void )
{
    int c;
    if ( buff == EOF ) {
        return getchar();
    } else {
        c = buff;
        buff = EOF;
        return c;
    }
}

void ungetch( int c )
{
    if ( buff != EOF ) {
        printf( "ungetch: can only hold one character\n" );
    } else {
        buff = c;
    }
}

int getop( char s[] )
{
    int i, c, sign;

    /* skip whitespace */
    while ( (s[0] = c = getch()) == ' ' || c == '\t' ) {
        ;
    }

    s[1] = '\0';
    if ( !isdigit(c) && c != '.' && c != '-' ) {
        return c; /* not a number */
    }

    i = 0;
    if ( c == '-' ) {
        sign = -1;
        s[++i] = c = getch();
        if ( !isdigit(c) && c != '.' ) {
            ungetch(c);
            return s[--i];
        }
    } else {
        sign = 1;
    }
    if ( isdigit(c) ) { /* collect integer component */
        while ( isdigit( s[++i] = c = getch() ) ) {
            ;
        }
    }
    if ( c == '.' ) { /* collect decimal component */
        while ( isdigit( s[++i] = c = getch() ) ) {
            ;
        }
    }
    s[i] = '\0';
    if ( c != EOF ) {
        ungetch(c);
    }

    return NUMBER;
}
