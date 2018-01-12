/* auto change line when the input is too long */
#include <stdio.h>
#define MAXLINE 10  // change line when longer than MAXLINE
#define MAXWORD 20  // max word length

int getline(char s[], int lim);
int findblank(char s[], int length);

main() 
{
    char line[MAXWORD];

    int i;
    while ((i = getline(line, MAXLINE)) > 0) {
        for (int j = 0; j < i; j++)
            putchar(line[j]);
        if (i == MAXLINE && line[i-1] != '\n')
            putchar('\n');
    }
}


/* getline: read a line into s, return length */
int getline(char s[], int lim) 
{
    int c, i;

    for (i = 0; i<lim && (c = getchar()) != EOF && c != '\n'; i++) 
        s[i] = c;

    if (c == '\n') 
        s[i++] = c;

    return i;
}

/* find the nearest blank before string end */
int findblank(char s[], int length)
{
    int i;
    for (i = length - 1; i >= 0; i--)
        if (s[i] == ' ')
            return i;

    return i;
}
