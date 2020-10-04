#include "rpn-args.h"


int main ( int argc, char *argv[] )
{
    int i;
    for ( i = 1 ; i < argc ; i++ ) {
        parseOperand( argv[i] );
    }
    printf( "\t%.8g\n", pop() );
}



int getop( char *operand )
{
    if ( !isdigit(*operand) && *operand != '.' && *operand != '-' ) {
        return *operand;  /* not a number */
    } else {
        return NUMBER;
    }
}

void parseOperand( char *operand )
{
    static double op2;
    static double variables[26];
    static double mostRecentPrint;

    switch ( getop( operand ) ) {
        case NUMBER:
            push( atof( operand ) );
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
            operand++;
            if ( *operand == '\0' ) {
                printf( "error: no variable name supplied" );
            } else if ( *operand >= 'a' && *operand <= 'z' ) {
                variables[(*operand-'a')] = pop();
            } else if ( *operand == '=' ) {
                mostRecentPrint = pop();
            } else {
                printf( "%c cannot be used as a variable. ", *operand );
                printf( "Please use a lowercase letter.\n" );
            }
            break;
        case 'a': /* push a stored variable back onto the stack */
            operand++;
            if ( *operand == '\0' ) {
                printf( "error: no variable name supplied" );
            } else if ( *operand >= 'a' && *operand <= 'z' ) {
                push( variables[(*operand-'a')] );
            } else if ( *operand == '=' ) {
                push( mostRecentPrint );
            } else {
                printf( "%c cannot be used as a variable. ", *operand );
                printf( "Please use a lowercase letter.\n" );
            }
            break;
        default:
            printf( "error: unknown command %s\n", operand );
            break;
    }
}
