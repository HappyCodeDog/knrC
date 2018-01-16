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


void itob(int n, char s[], int b)
{
    int i, sign;
    
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        int d = n % b;
        s[i++] = d > 9 ? 'A'+(d-10) : '0'+d;
    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

main()
{
    int n;
    char s[MAXWORD];
    int b;
    scanf("%d %d", &n, &b);
    itob(n, s, b);
    fputs(s, stdout);
}
