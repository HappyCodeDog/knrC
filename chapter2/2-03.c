/* write a function htoi(s), which converts a string of hexadecimal 
 * digits into its equivalent integer value
 */
#include <ctype.h>
#include <stdio.h>
#define MAXWORD 20

int htoi(char s[])
{
    int i, n;

    i = n = 0;
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))  // 0x or 0X
        i += 2;

    for (; isxdigit(s[i]); ++i)
        if (isdigit(s[i]))
            n = 16 * n + (s[i] - '0');
        else
            n = 16 * n + (tolower(s[i]) - 'a' + 10);

    return n;
}

main()
{
    int c, i = 0;
    char s[MAXWORD];

    printf("input a hexadecimal number:");
    while ((c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    printf("its integer value is: %d\n", htoi(s));
}


