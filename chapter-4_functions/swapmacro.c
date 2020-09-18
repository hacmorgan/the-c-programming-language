#include <stdio.h>

#define paste( front, back ) front ## back
#define swap( t, x, y ) t a = x ; x = y ; y = a


int main()
{
    int paste( my, Integer ) = 5;
    int paste( another, Integer ) = 6;

    printf( "myInteger = %d, anotherInteger = %d\n", myInteger, anotherInteger );

    swap( int, myInteger, anotherInteger );
    
    printf( "myInteger = %d, anotherInteger = %d\n", myInteger, anotherInteger );
}
