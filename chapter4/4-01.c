#include <stdio.h>
#include <string.h>
#define MAXWORD 20

int strrindex(char s[], char t[])
{
    int i, j, k;

    /* i = strlen(s)-2 because we want to skip the last character
       '\n', so does k */
    for (i = strlen(s)-2; i >= 0; i--) {
        for (j=i, k=strlen(t)-2; k >= 0 && s[j]==t[k]; j--, k--)
            ;
        if (k < 0)
            return j + 1;
    }
    return -1;
}

main()
{
    char s[MAXWORD], t[MAXWORD];
    printf("string s:");
    fgets(s, MAXWORD, stdin);
    printf("string t:");
    fgets(t, MAXWORD, stdin);
    printf("%d\n", strrindex(s, t));
}

