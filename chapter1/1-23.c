/* Remove all comments from a C program */
/* My code is like a shit! But it works in the normal conditions */
#include <stdio.h>

main() 
{
    int inquote = 0;
    int instarcomment = 0;
    int inslashcomment = 0; 
    int star = 0;   // is the previous char a '*'?
    int slash = 0;  // is the previous char a '/'?

    int c;

    while ((c = getchar()) != EOF) {
        if (inslashcomment) {
            if (c == '\n') {
                inslashcomment = 0;
                putchar('\n');
            }
            continue;
        }
        else if (instarcomment) {
            if (c == '*')
                star = 1;

            if (c == '/' && star == 1) {
                instarcomment = 0;
                star = 0;
            }
            continue;
        }
        else if (inquote) {
            if (c == '\"')
                inquote = 0;
            putchar(c);
            continue;
        }

        if (c == '\"')
            inquote = 1;
        else if (c == '/') {
            if (slash == 1) {   // whether there's a "//"
                inslashcomment = 1;
                slash = 0;
            }
            else 
                slash = 1;
            
            continue;   // don't output this '/' first
        }
        else if (c == '*') {
            if (slash == 1) {    // whether there's a "/*"
                instarcomment = 1;
                slash = 0;
                continue;
            }
        }
        else if (slash == 1) {
            putchar('/');
            slash = 0;
        }

        putchar(c);
    }
}
