#include <stdio.h>
#include <string.h>

void itoa( int n, char s[] )
{
    static int i, original; /* static variables are initialised to 0 */
    if ( n < 0 ) {
        s[i++] = '-';
        n = -n; /* doesn't handle the largest negative number for now */
    }
    if ( original == 0 ) {
        original = n;
    }
    if ( n / 10 > 0 ) {
        itoa( n/10, s );
    }
    s[i++] = n % 10 + '0';
    if ( n == original ) {
        s[i++] = '\0';
    }
}

void reverse( char s[] )
{
    static int i, j, first;
    int c;

    c = s[i++];
    if ( first == 0 ) {
        first = c;
    }

    if ( c != '\0' ) {
        reverse(s);
        s[j++] = c;
    }

    if ( c == first ) {
        s[j++] = '\0';
    }
}

int main()
{
    int largestNegativeNumber = -2147483648;
    int n = -1234;
    char s[10];
    itoa( n, s );
    printf( "n as int: %d, n as string: %s\n", n, s );

    char r[10] = "Hello!";
    printf( "Forward string: %s\n", r );
    reverse(r);
    printf( "Reversed string: %s\n", r );
    return 0;
}
