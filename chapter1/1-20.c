#include <stdio.h>
#define TABSTOP 8 

main() 
{
    int c;
    int i = 0;  // the current cursor's position in each line
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {    // replace '\t' with blanks
            for (int j = 0; j < TABSTOP - (i%TABSTOP); j++)
                putchar(' ');
            i += TABSTOP - (i % TABSTOP);
            continue;
        }

        i++;
        putchar(c);

        if (c == '\n')
            i = 0;
    }
}
