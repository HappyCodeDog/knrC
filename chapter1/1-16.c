// undone
#include <stdio.h>
#define MAXLINE 1000
#define ARBILENGTH 5

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main() 
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char s[],  int lim)
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
