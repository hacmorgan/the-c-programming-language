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

int main()
{
    int largestNegativeNumber = -2147483648;
    int n = -1234;
    char s[10];
    itoa( n, s );
    printf( "n as int: %d, n as string: %s\n", n, s );
    return 0;
}
