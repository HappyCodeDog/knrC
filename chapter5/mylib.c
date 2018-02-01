#include <stdio.h>
#define BUFSIZE 100
#define MAXLEN 1000
#define MAXLINES 20

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
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

int readline(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines = 0;

    while ((len = getline(linestor, MAXLEN)) > 0)
        if (nlines >= maxlines || len > MAXLEN)
            return -1;
        else {
            *(linestor+len-1) = '\0';   // delete newline
            lineptr[nlines++] = linestor;
            linestor += len;
        }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
