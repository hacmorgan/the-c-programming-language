#include <stdio.h>


static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};


int day_of_year( int year, int month, int day )
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if ( month > 12 || day > daytab[leap][month] || month < 1 || day < 1 ) {
        printf( "error: invalid date\n" );
        return -1;
    }
    
    for ( i = 1 ; i < month ; i++ ) {
        day += daytab[leap][i];
    }
    return day;
}


int sum( char *row )
{
    int result = 0;
    for ( int i = 0 ; i <= 12 ; i++ ) {
        result += *row++;
    }
    return result;
}

void month_day( int year, int yearday, int *pmonth, int *pday )
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if ( pmonth == NULL || pday == NULL ) {
        printf( "error: one or more NULL pointers supplied\n" );
        return;
    }
    if ( yearday > sum( daytab[leap] ) || yearday < 1 ) {
        printf( "error: invalid yearday\n" );
    }
    
    for ( i = 1 ; yearday > daytab[leap][i] ; i++ ) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}


int main()
{
    int year = 2020;
    int month = 9;
    int day = 26;

    int yearday = day_of_year( year, month, day );
    printf( "%d/%d/%d is the %dth day of %d\n",
            day, month, year, yearday, year );
    
    int newday, newmonth;
    month_day( year, yearday, &newmonth, &newday );
    printf( "The %dth day of %d is %d/%d/%d\n",
            yearday, year, newday, newmonth, year );

    printf( "There are %d days in a normal year, and %d days in a leap year\n",
            sum( daytab[0] ), sum( daytab[1] ) );
    
    return 0;
}
