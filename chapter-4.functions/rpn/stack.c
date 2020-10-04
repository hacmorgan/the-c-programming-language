#include <stdio.h>
#include "calc.h"

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum depth of value stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value satck */

void push( double f )
{
    if ( sp < MAXVAL ) {
        val[sp++] = f;
    } else {
        printf( "error: stack full, can't push %g\n", f );
    }
}

double pop( void )
{
    if ( sp > 0 ) {
        return val[--sp];
    } else {
        printf( "error: stack empty\n" );
        return 0.0;
    }
}

double top( void )
{
    double top = pop();
    push( top );
    printf( "\t%.8g\n", top );
    return top;
}

void duplicate( void )
{
    double top = pop();
    push( top );
    push( top );
}

void swap( void )
{
    double top  = pop();
    double topp = pop();
    push( top );
    push( topp );
}

void clear( void )
{
    sp = 0;
}
