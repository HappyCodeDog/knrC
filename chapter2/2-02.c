/* rewrite the for loop without using "&&" and "||" */
#include <stdio.h>
#define MAXLINE 5

int getline(char s[], int lim);

main() 
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
        printf("%s", line);
}

int getline(char s[], int lim)
{
    int c, i;

    for (i=0; (i<lim-1) & ((c=getchar())!=EOF) & (c!='\n'); ++i)
        s[i] = c;
    if ((i>=lim-1) | (c == '\n')) {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
