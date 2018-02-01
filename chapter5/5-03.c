#include <string.h>
#include <stdio.h>

// strcat: concatenate t to end of s; s must be big enough
void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}

main()
{
//    char *s = "hello ";
//    char *t = "world!";
    char s[20] = "hello ";
    char t[20] = "world!";
    strcat(s, t);
    printf("%s\n", s);
}
