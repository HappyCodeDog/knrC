#include <stdio.h>

main() 
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b') // can't get a '\b'
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else 
            putchar(c);
    }
}
