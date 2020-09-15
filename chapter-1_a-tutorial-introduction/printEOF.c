#include <stdio.h>

int main()
{
    char a = EOF;
    int b = '\0';
    printf( "EOF's integer representation: %d\n", a );
    printf( "Next character after z: %c\n", ('z'+1) );
    printf( "\0's integer representation: %c\n", b );
}
