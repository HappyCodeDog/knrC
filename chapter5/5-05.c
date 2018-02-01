#include <stdio.h>
#include <string.h>

char *strncpy(char s[], char t[], int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

main()
{
    char s[20];
    char t[20];
    printf("string s: ");
    fgets(s, 20, stdin);
    printf("string t: ");
    fgets(t, 20, stdin);
    printf("%d\n", strncmp(s, t, 10));
//    strncat(s, t, 10);
//    printf("%s\n", s);
//    printf("%s\n", strncpy(s, t, 10));

}

char *strncpy(char s[], char t[], int n)
{
    int i, l = strlen(t);

    for (i = 0; i <= n && i <= l; i++) 
        s[i] = t[i];

    while (i <= n)
        s[i++] = '\0';

    return s;
}

void strncat(char *s, char *t, int n)
{
    s += strlen(s);
    strncpy(s, t, n);
}

int strncmp(char *s, char *t, int n)
{
    if (n > strlen(t))
        n = strlen(t);
    while (*s++ == *t++ && n-- > 0)
        ;
    if (n == 0)
        return 0;
    else
        return (*--s > *--t) ? 1 : -1;
}
