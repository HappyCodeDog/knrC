#include <stdio.h>
#define MAXWORD 20

void itoa(int n, char s[])
{
    static int i = 0;
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if ((n / 10) > 0)
        itoa(n / 10, s);
    
    s[i++] = n % 10 + '0';
    // if it's not the end, this '\0' will be overwritten
    s[i] = '\0';    
}

main()
{
    char s[MAXWORD];
    int n = -2541;
    itoa(n, s);
    printf("%s", s);
}
