#include <stdio.h>
#define MAXLINE 20

void reverse(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;

    char temp[i];
    for (int j = 0; j < i; j++) 
        temp[j] = s[j];

    for (int j = 0; j < i; j++)
        s[j] = temp[i-1-j];
}

main()
{
    char s[MAXLINE];
    
    int c, i = 0;

    while ((c = getchar()) != '\n')
        s[i++] = c;

    s[i] = '\0';
    
    reverse(s);
    printf("%s\n", s);
}
