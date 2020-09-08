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
        
        }
    }
}
