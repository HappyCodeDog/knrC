#include <stdio.h>
#define MAXLINE 1000
#define MAXLINENUM 20
#define LENGTH 10   // min displayed line length

int getline(char s[], int lim);
void copy(char to[], char from[]);

main() 
{
    char line[MAXLINE];
    char longlines[MAXLINENUM][MAXLINE];
    int i = 0;

    int l;
    while ((l = getline(line, MAXLINE)) > 0) 
        if (l > LENGTH)
            copy(longlines[i++], line);
            
    printf("\nlines longer than %d:\n", LENGTH);
    for (int j = 0; j < i; j++)
        printf("%s", longlines[j]);
}

int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != EOF; i++)
        ;
}
