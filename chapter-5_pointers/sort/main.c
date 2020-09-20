#include "sort.h"

int main()
{
    /* static char *lineptrr[MAXLINES]; /\* pointers to text lines *\/ */

    int nlines;

    if ( (nlines = readlines(lineptrr, MAXLINES)) >= 0 ) {
        qsort( lineptrr, 0, nlines-1 );
        writelines( lineptrr, nlines );
        return 0;
    } else {
        printf( "error: input too big to sort\n" );
        return 1;
    }
}
