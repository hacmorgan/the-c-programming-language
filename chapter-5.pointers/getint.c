#include <stdio.h>
#include <ctype.h>


int getint( int* );
int getfloat( float* );

int main()
{
    int n;
    float m;
    /* printf( "Before running getint, n = %d\n", n ); */
    /* getint(&n); */
    /* printf( "After running getint, n = %d\n", n ); */
    printf( "Before running getfloat, m = %f\n", m );
    getfloat(&m);
    printf( "After running getfloat, m = %f\n", m );
}


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

/* getint: get next integer from input onto *pn */
int getint( int *pn )
{
    int c, sign;

    while ( isspace( c = getch() ) ) {
        ;
    }

    if ( !isdigit(c) && c != EOF && c != '+' && c != '-' ) {
        ungetch(c); /* it's not a number */
        return 0;
    }

    sign = ( c == '-' ) ? -1 : 1;
    if ( c == '+' || c == '-' ) {
        c = getch();
        if ( !isdigit(c) ) {
            ungetch(c);
            return c;
        }
    }

    for ( *pn = 0 ; isdigit(c) ; c = getch() ) {
        *pn = 10 * *pn + ( c - '0' );
    }
    *pn *= sign;

    if ( c != EOF ) {
        ungetch(c);
    }
    return c;
}

int getfloat( float *pn )
{
    int c;
    float sign;
    float power = 1.0;

    /* skip whitspace */
    while ( isspace( c = getch() ) ) {
        ;
    }

    if ( !isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'  ) {
        ungetch(c); /* it's not a number */
        return 0;
    }

    /* determine sign, return if sign not proceeded by a digit */
    sign = ( c == '-' ) ? -1 : 1;
    if ( c == '+' || c == '-' ) {
        c = getch();
        if ( !isdigit(c) && c != '.' ) {
            ungetch(c);
            return c;
        }
    }

    /* collect integer component */
    for ( *pn = 0 ; isdigit(c) ; c = getch() ) {
        *pn = 10.0 * *pn + ( c - '0' );
    }
    if ( c == '.' ) {
        c = getch();
    }
    /* collect fractional component */
    for ( ; isdigit(c) ; c = getch() ) {
        *pn = 10.0 * *pn + ( c - '0' );
        power *= 10;
    }
    
    
    *pn = *pn * sign / power;

    if ( c != EOF ) {
        ungetch(c);
    }
    return c;
}
