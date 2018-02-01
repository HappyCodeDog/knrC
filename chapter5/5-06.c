// I just rewrite 2 functions, because I think others are no 
// different
#include <stdio.h>
#include <ctype.h>

int getline(char s[], int lim);
int atoi(char *s);

main()
{

}

int getline(char *s, int lim)
{
    char *start = s;
    int c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s-start;
}

int atoi(char *s)
{
    int n = 0;

    while (isspace(*s))     // skip white spaces
        s++;
    while (isdigit(*s))
        n = 10 * n + (*s++ - '0');

    return n;
}
