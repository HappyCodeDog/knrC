// tail: print the last n lines
#include <stdio.h>
#include "mylib.h"
#define DEFAULTLINES 10
#define MAXLINES 100    // max # of lines to print 
#define MAXLEN 100      // max length of an input line

int main(int argc, char *argv[])
{
    int n;      // the last n lines should be output

    if (argc == 1)
        n = DEFAULTLINES;
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(*argv+1);

    int len;
    int nlines = 0;     // # of lines have been read in
    char *lines[MAXLINES];
    char linestor[MAXLEN];
    char *p;

    while (len = getline(linestor, MAXLEN) > 0) {
        if ((p = (char *)malloc(len)) == NULL) {
            printf("error: can't allocate storages!\n");
            exit(1);
        }
        strcpy(p, linestor);
        nlines++;
        if (nlines > MAXLINES)
            nlines = MAXLINES;
}
