#include <stdio.h>
#define MAXWORD 20

void squeeze(char a[], char b[])
{
    char c = b[0];

    /* if the charater in a matches any character in b, then 
       replace it with the first character in b */
    for (int i = 0; a[i] != '\0'; ++i)
        for (int j = 0; b[j] != '\0'; ++j)
            if (a[i] == b[j])
                a[i] = c;   // use c as a delete sign 

    /* delete the matched characters in a */
    int j = 0;
    for (int i = 0; a[i] != '\0'; ++i)
        if (a[i] != c) 
            a[j++] = a[i];
        else
            continue; 

    a[j] = '\0';
} 

main() 
{
    char a[MAXWORD], b[MAXWORD];

    printf("string 1: ");
    fgets(a, MAXWORD, stdin);
    printf("string 2: ");
    fgets(b, MAXWORD, stdin);

    squeeze(a, b);
    printf("after squeeze: %s\n", a);
}

