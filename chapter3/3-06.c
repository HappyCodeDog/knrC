#include <stdio.h>
#include <string.h>
#define MAXWORD 20

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }   
}


void itoa(int n, char s[], int w)
{
    int i, sign;
    
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = '0' + n % 10;
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

main()
{
    int n;
    char s[MAXWORD];
    int w;
    scanf("%d %d", &n, &w);
    itoa(n, s, w);
    fputs(s, stdout);
}
