#include <stdio.h>

main() 
{
    int c;
    int blanks = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (blanks == 0) {
                blanks = 1;
                putchar(c);
            }
        }
        else {
            blanks = 0;
            putchar(c);
        }
    }
}
