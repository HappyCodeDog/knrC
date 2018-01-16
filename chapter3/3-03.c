#include <stdio.h>
#include <ctype.h>
#define MAXWORD 50

void expand(char s1[], char s2[])
{
    int i, j = 0;
    char c;

    putchar(s1[0]); // the first char should be output for sure

    for (i = 1; s1[i] != '\0'; i++) 
        if (s1[i] == '-' && s1[i+1] > s1[i-1]) {
            c = s1[i-1];
            c++;    // s1[i-1] is already output, so inc c
            while (c < s1[i+1])
                s2[j++] = c++;
        }
        else
            s2[j++] = s1[i];
            
    s2[j] = '\0';
}

main()
{
    char s1[MAXWORD], s2[MAXWORD];
    fgets(s1, MAXWORD, stdin);
    expand(s1, s2);
    fputs(s2, stdout);
}
