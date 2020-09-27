#include <stdio.h>
#include <string.h>

#define MAXLINES  5000
#define MAXLEN    1000

/* does this need to be external? */
static char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines( char *lineptr[], int nlines );
void writelines( char *lineptr[], int nlines );

void qsort( void *lineptr[], int left, int right,
            int (*comp)( void *, void * ) );

int numcmp( char *, char * );

int getline( char *s, int lim );
char *alloc( int );
