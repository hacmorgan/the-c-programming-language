char* skipStart( char* s, char t )
{
    for ( ; *s != t && *s != '\0' ; s++ ) {
        ;
    }
    return s;
}

int strend( char* s, char* t )
{
    s = skipStart( s, *t );
    if ( *s == '\0' ) {
        return 0;
    }

    while ( *++s == *++t && *s != '\0' && *t != '\0' ) {
        ;
    }

    if ( *t == '\0' && *s == '\0' ) {
        return 1;
    } else {
        return 0;
    }
}
