#include <stdio.h>

int buff = EOF;
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
