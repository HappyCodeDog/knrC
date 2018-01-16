#include <stdio.h>
#include <ctype.h>

char lower(char c)
{
    return isupper(c) ? tolower(c) : c;
}

main()
{
    int c;

    while ((c = getchar()) != EOF)
        printf("%c", lower(c));
}
