#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define NUMBER '0'

void parseOperand( char *operand );

void push( double f );
double pop( void );
double top( void );
void duplicate( void );
void swap( void );
void clear( void );
