#include <stdio.h>
#include <stdlib.h> /* for atof */
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

/* reverse polish notation calculator */
/* we will start with one monolithic file, and aim to split it up later */

int getop( char [] );
void push( double );
double pop( void );
double top( void );
void duplicate( void );
void swap( void );
void clear( void );

int main()
{
    int type;
    double op2;
    double variables[26] = { 0 };
    double mostRecentPrint;
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
                printf( "error: division by zero!\n" );
            }
            break;
        case '%':
          op2 = pop();
          if ( op2 != 0.0 ) {
              push( fmod( pop(), op2 ) );
          } else {
              printf( "error: division by zero!\n" );
          }
          break;
        case '\n':
            mostRecentPrint = pop();
            printf( "\t%.8g\n", mostRecentPrint );
            break;
        case 'f':
            mostRecentPrint = top(); /* print top element */
            break;
        case 'd':
            duplicate(); /* duplicate top element */
            break;
        case 'w':
            swap(); /* swap top two elements */
            break;
        case 'c':
            clear(); /* clear stack */
            break;
        case 's':
            push( sin( pop() ) );
            break;
        case 'e':
            push( exp( pop() ) );
            break;
        case 'p':
            op2 = pop();
            push( pow( pop(), op2 ) );
            break;
        case 'v': /* store result of pop() in a variable */
            if ( (type=getop(s)) == '\n' ) {
                top();
            } else if ( type >= 'a' && type <= 'z' ) {
                variables[(type-'a')] = pop();
            } else if ( type == '=' ) {
                mostRecentPrint = pop();
            } else {
                printf( "%c cannot be used as a variable. Please use a lowercase letter.\n" );
            }
            break;
        case 'a': /* push a stored variable back onto the stack */
            if ( (type=getop(s)) == '\n' ) {
                top();
            } else if ( type >= 'a' && type <= 'z' ) {
                push( variables[(type-'a')] );
            } else if ( type == '=' ) {
                push( mostRecentPrint );
            } else {
                printf( "%c cannot be used as a variable. Please use a lowercase letter.\n" );
            }
            break;
        default:
            printf( "error: unknown command %s\n", s );
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


#include <ctype.h>

int getch( void );
void ungetch( int );

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

void ungets( char s[] )
{
    int i;
    for ( i=0; s[i] != '\0'; i++ ) {
        ungetch( s[i] );
    }
}


#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buffer */

int getch_buf( void )  /* get a (possibly pushed back) character */
{
    return ( bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch_buf( int c ) /* push character back onto the buffer */
{
    if ( bufp >= BUFSIZE ) {
        printf( "ungetch: too many characters\n" );
    } else {
        buf[bufp++] = c;
    }
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
