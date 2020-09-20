#include "sort.h"

int main()
{
    static char *lineptr[MAXLINES]; /* pointers to text lines */

    int nlines;

    if ( (nlines = readlines(lineptr, MAXLINES)) >= 0 ) {
        qsort( lineptr, 0, nlines-1 );
        writelines( lineptr, nlines );
        return 0;
    } else {
        printf( "error: input too big to sort\n" );
        return 1;
    }
}
