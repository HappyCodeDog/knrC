#include <stdio.h>
#include "mylib.h"
#define MAXLEN 1000     // max length of any input line
#define MAXLINES 20

/*
int readline(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
*/

main()
{
    char *lineptr[MAXLINES], linestor[MAXLEN];
    int nlines = readline(lineptr, linestor, MAXLINES);
    writelines(lineptr, nlines);
}

/*  these functions are defined in mylib.c
int readline(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines = 0;

    while ((len = getline(linestor, MAXLEN)) > 0)
        if (nlines >= maxlines)
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
*/
