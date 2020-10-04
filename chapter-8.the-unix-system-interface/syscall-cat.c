#include <sys/file.h>
#include <string.h>


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
