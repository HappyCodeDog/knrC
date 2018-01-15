#include <stdio.h>
#define MAXWORD 20

int squeeze(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; ++i)
        for (int j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;

    return -1;
}

main() 
{
    char a[MAXWORD], b[MAXWORD];

    printf("first string:");
    fgets(a, MAXWORD, stdin); 
    printf("second string:");
    fgets(b, MAXWORD, stdin);
    int i = squeeze(a, b);
    printf("the first matched char's position: %d\n", i);
}

