#include <stdio.h>
#include <stdlib.h> /* for atof */

#define MAXOP 100
#define NUMBER '0'

int getop( char [] );
void push( double );
double pop( void );

/* reverse polish notation calculator */
/* we will start with one monolithic file, and aim to split it up later */

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ( (type=getop(s)) != EOF ) {
        switch (type) {
        case NUMBER:
            push( atof(s) );
            break;
        case '+':
            push( pop() + pop() );
            break;
        case '*':
            push( pop() * pop() );
            break;
        case '-':
            op2 = pop();
            push( pop() - op2 );
            break;
        case '/':
            op2 = pop();
            if ( op2 != 0.0 ) {
                push( pop() / op2 );
            } else {
                printf( "Error: division by zero!\n" );
            }
            break;
        case '\n':
            printf( "\t%.8g\n", pop() );
            break;
        default:
            printf( "Error: unknown command %s\n", s );
            break;
        }
    }

    return 0;
}


#define MAXVAL 100 /* maximum depth of value stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value satck */

void push( double f )
{
    if ( sp < MAXVAL ) {
        val[sp++] = f;
    } else {
        printf( "Error: stack full, can't push %g\n", f );
    }
}

double pop( void )
{
    if ( sp > 0 ) {
        return val[--sp];
    } else {
        printf( "Error: stack empty\n" );
        return 0.0;
    }
}


#include <ctype.h>

int getch( void );
void ungetch( int );

int getop( char s[] )
{
    int i, c;

    /* skip whitespace */
    while ( (s[0] = c = getch()) == ' ' || c == '\t' ) {
        ;
    }

    s[1] = '\0';
    if ( !isdigit(c) && c != '.' ) {
        return c; /* not a number */
    }

    i = 0;
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


