#include "sort.h"


void swap( void *v[], int i, int j );

/* quicksort:  */
void qsort( void *v[], int left, int right,
            int (*comp)( void *, void * ) )
{
    int i, last;

    if ( left >= right ) {
        return;  /* do nothing for < 2 elements */
    }

    swap( v, left, (left+right)/2 );
    last = left;
    for ( i = left+1 ; i <= right ; i++ )  {
        if ( (*comp)( v[i], v[left] ) < 0 ) {
            swap( v, ++last, i );
        }
    }
    swap( v, left, last );

    qsort( v, left, last-1, comp );
    qsort( v, last+1, right, comp );
}

void swap( void *v[], int i, int j )
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
