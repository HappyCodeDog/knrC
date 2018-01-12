/* entab */

#include <stdio.h>
#define TABSTOP 8

main() 
{
    int c;
    int i = 0;  // current cursor's position in each line
    int space_start = -1;   // the first space's position of 
                            // continous spaces

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (space_start == -1)   // c is the first space
                space_start = i;
            if (i % 8 == 7) { // these spaces can be replaced by tab
                putchar('\t'); 
                space_start = -1;
            }
            i++;
            continue;
        }

        // c isn't a space
        if (space_start != -1) {    // these spaces can't be replaced
            for (int j = 0; j < i - space_start; j++)
                putchar(' ');
            space_start = -1;
        } 
        putchar(c);
        i++;

        if (c == '\n')  // new line
            i = 0;
    }
}
