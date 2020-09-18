#include "strutils.h"

int main()
{
    /* char s[20] = "Hello, "; */
    /* char *t = "world!"; */
    /* strcatt( s, t ); */
    /* printf( "The new string is: %s\n", s ); */

    char *u = "Hello, world!";
    char *v = "world!";
    if ( strend( u, v ) ) {
        printf( "v is at the end of u\n" );
    } else {
        printf( "v is NOT at the end of u\n" );
    }
}
