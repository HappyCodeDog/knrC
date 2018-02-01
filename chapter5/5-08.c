#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day_fo_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (month < 1 || month > 12)
        return -1;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (day < 1 || day > daytab[leap][month])
        return -1;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < 12 && yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    if (yearday > daytab[leap][i]) {
        *pmonth = -1;
        *pday = -1;
    }
    else {
        *pmonth = i;
        *pday = yearday;
    }
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
