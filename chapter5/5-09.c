// rewrite the routines day_of_year and month_day with pointers 
// instead of indexing
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day_fo_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    while (--month > 0)
        day += *++p;
    return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap]; 
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}


main()
{
    /*
    int year, month, day;
    printf("year:");
    scanf("%d", &year);
    printf("month:");
    scanf("%d", &month);
    printf("day:");
    scanf("%d", &day);
    printf("day of year: %d\n", day_of_year(year, month, day));
    */

    int year, yearday, month, day;
    printf("year:");
    scanf("%d", &year);
    printf("day of year:");
    scanf("%d", &yearday);
    month_day(year, yearday, &month, &day);
    printf("month: %d, day: %d\n", month, day);
}
