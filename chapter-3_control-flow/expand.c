#include <stdio.h>
#include <string.h>

/*
- takes a string such as a-z and expands it out to abc...xyz
- must also account for -a-z -> zyx...cba
*/

int isValidChar( char s )
{
    if ( ( s >= 'a' && s <= 'z' ) || ( s >= '0' && s <= '9' ) || s == '-' ) {
        return 1;
    } else {
        return 0;
    }
}

void expand( char s1[], char s2[] )
{
    // Skip any invalid leading characters
    int i = 0;
    for ( i = 0; ! isValidChar(s1[i]) && i < strlen(s1) ; i++ ) {
        printf( "Invalid character encountered\n" );
    }
    printf( "s1[%d] = %c\n", i, s1[i] );

    // Determine whether or not to reverse the string based on the 1st char
    int reverse;
    if ( s1[i] == '-' ) {
        reverse = 1;
        i++;
    } else {
        reverse = 0;
    }
    
    // Loop over all the integers between
    int j = 0;
    while ( s1[i] != '\0' && s1[i+2] != '\0' ) {
        int x, y;
        for ( x = s1[i+0], y = s1[i+2] ; x <= y ; x++ ) {
            s2[j] = x;
            j++;
        }
        i += 3;
        while ( s1[i] == '-' ) {
            i++;
        }
    }
    s2[j+1] = '\0';
}


int main()
{
    char s1[10] = "a-z0-9";
    char s2[100];
    expand(s1, s2);
    printf("Original string: %s\nExpanded string: %s\n", s1, s2);
    return 0;
}
