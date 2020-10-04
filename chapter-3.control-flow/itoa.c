#include <stdio.h>
#include <string.h>

/* 
Exercise 3-4:
Q: Why does this not work with the biggest negative number?
A: The biggest negative number has magnitude 1 greater than the biggest
   positive number, so n = -n (as in the original code) will overflow
*/


void reverse( char s[] )
{
    int c, i, j;
    for ( i=0, j=strlen(s)-1 ; i < j ; i++, j-- ) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoaOld( int n, char s[] )
{
    int i, sign;

    if ( (sign = n) < 0 ) {
        n = -n;
    }
    
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ( (n /= 10) > 0 );
    if ( sign < 0 ) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

/* itoa: convert n to characters in s */
void itoaNew( int n, char s[], int f )
{
    int i, sign;

    sign = n;
    
    i = 0;
    do {
        if ( n >= 0 ) {
            s[i++] = n % 10 + '0';
        } else {
            s[i++] = -(n % 10) + '0';
        }
    } while ( (n /= 10) != 0 );
    if ( sign < 0 ) {
        s[i++] = '-';
    }
    while ( i < f ) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

void itob( int n, char s[], int b )
{
    int i, m, sign;

    sign = n;
    
    i = 0;
    do {
        if ( n >= 0 ) {
            m = n % b;
        } else {
            m = -(n % b);
        }
        if ( m < 10 ) {
            s[i++] = m + '0';
        } else {
            s[i++] = (m - 10) + 'a';
        }
    } while ( (n /= b) != 0 );
    if ( sign < 0 ) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int largestNegativeNumber = -2147483648;
    int n = 2;
    char s[10];
    /* itob( n, s, 16 ); */
    int width = 8;
    for ( int i = 0; i < width - 1; i++ ) {
        itoaNew( ( n *= 10 ), s, width);
        printf("%s\n", s);
    }
    return 0;
}
