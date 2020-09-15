#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

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
