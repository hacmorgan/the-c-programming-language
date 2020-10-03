#include <sys/file.h>
#include <string.h>

#define BUFSIZE 4096

int fd;

int read( int fd, char *buf, int n );
int write( int fd, char *buf, int n );
int open( const char *name, int flags, ... );
int close( int fd );

int filecopy( int fdin, int fdout );


int main( int argc, char *argv[] )
{
    if ( argc == 1 ) {  /* no args, copy stdin */
        filecopy( 0, 1 );
    } else {
        while ( --argc > 0 ) {
            fd = open( *++argv, O_RDONLY );
            if ( fd == -1 ) {
                char *errormsg = "error reading file\n";
                write( 2, "error reading file\n", strlen(errormsg) + 1 );
            } else {
                filecopy( fd, 1 );
                close( fd );
            }
        }
    }
    return 0;
}


int filecopy( int fdin, int fdout )
{
    int n;
    char buf[BUFSIZE];

    while ( (n = read(fdin, buf, BUFSIZE)) != 0 ) {
        if ( n == -1 ) {
            char *errormsg = "error reading from file\n";
            write( 2, errormsg, strlen(errormsg) + 1 );
        }
        write( fdout, buf, n );
    }
}
