/* copy string t to the end of string s */
int strcatt( char *s, char *t )
{
    for ( ; *s != '\0' ; s++ ) {
        ;
    }
    for ( ; *t != '\0' ; ) {
        *s++ = *t++;
    }
    *s = '\0';
}
