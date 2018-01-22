#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    static int i = 0, j = strlen(s) - 1;
    while (i < j) {
        int temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
        reverse(s);
    }
}

main()
{
    char s[] = "apple";
    reverse(s);
    printf("%s", s);
}

