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

void itoa(int n, char s[])
{
    long long l = (long long)n;

    if (n < 0)
        l = -l;
    
    int i = 0;
    do {
        s[i++] = l % 10 + '0';
    } while ((l /= 10) > 0);
    if (n < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

main()
{
    int n = ((unsigned)~0) ^ ((unsigned)~0 >> 1); // minimum int
    char s[MAXWORD];
    //scanf("%d", &n);
    itoa(n, s);
    fputs(s, stdout);
}
