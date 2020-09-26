#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];  /* storage for alloc */
static char *allocp = allocbuf;              /* next free position */

char *alloc( int n )
{
    if ( allocbuf + ALLOCSIZE - allocp >= n ) { /* if it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else {
        return 0; /* not enough room */
    }
}

void afree( char *p )
{
    if ( p >= allocbuf && p < allocbuf + ALLOCSIZE ) {
        allocp = p;
    }
}
