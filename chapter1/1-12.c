#include <stdio.h>

main() 
{
    int c, newline = 0;
    
    while ((c = getchar()) != EOF) 
        if (c >= 'A' && c <= 'z') {
            newline = 0;
            putchar(c);
        }
        else if (newline == 0) {
            printf("\n");
            newline = 1;
        }
}
