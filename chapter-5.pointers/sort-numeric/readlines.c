#include "sort.h"

int readlines( char *lineptr[], int maxlines )
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ( (len = getline(line, MAXLEN)) > 0 ) {
        if ( nlines >= maxlines || ( p = alloc(len) ) == NULL ) {
            return -1;
        } else {
            line[len-1] = '\0'; /* delete newline */
            strcpy( p, line );
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines( char *lineptr[], int nlines )
{
    while ( nlines-- > 0 ) {
        printf( "%s\n", *lineptr++ );
    }
}
