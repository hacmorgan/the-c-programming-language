#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof( char s[] )
{
    double val, power, exponent, result;
    int i, sign, exponentSign;

    for ( i=0 ; isspace(s[i]) ; i++ ) {
        ; /* skip whitespace */
    }
    
    sign = ( s[i] == '-' ) ? -1 : 1;
    if ( s[i] == '+' || s[i] == '-' ) {
        i++;
    }
    
    for ( val=0 ; isdigit(s[i]) ; i++ ) {
        val = 10.0 * val + ( s[i] - '0' );
    }
    if ( s[i] == '.' ) {
        i++;
    }
    for ( power=1.0 ; isdigit(s[i]) ; i++ ) {
        val = 10.0 * val + ( s[i] - '0' );
        power *= 10;
    }
    result = sign * val / power;
    if ( s[i] == 'e' || s[i] == 'E' ) {
        if ( s[++i] == '-' ) {
            exponentSign = -1;
            i++;
        } else {
            exponentSign = 1;
        }
        for ( exponent=0 ; isdigit(s[i]) ; i++ ) {
            exponent = 10 * exponent + ( s[i] - '0' );
        }
        if ( exponentSign == -1 ) {
            exponent = -exponent;
        }
        while ( exponent < 0 ) {
            result /= 10;
            exponent++;
        }
        while ( exponent > 0 ) {
            result *= 10;
            exponent--;
        }
    }

    return result;
}

