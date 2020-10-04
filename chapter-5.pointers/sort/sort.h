#include <stdio.h>
#include <string.h>

#define MAXLINES  5000
#define MAXLEN    1000

static char *lineptrr[MAXLINES]; /* pointers to text lines */

int  readlines(  char *lineptrr[], int nlines );
void writelines( char *lineptrr[], int nlines );

void qsort( char *lineptrr[], int left, int right );
void swap( char *v[], int left, int right );

int getline( char *s, int lim );
char *alloc( int );
