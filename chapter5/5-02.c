#include <stdio.h>
#include <ctype.h>
#include "mylib.h"

int getfloat(float *pf);

main()
{
    float f;
    getfloat(&f);
    printf("%g\n", f);
}


/* getfloat: get next float number from input into *pf */
int getfloat(float *pf)   
{
    int c, sign, d, power;

    while (isspace(c = getch()))    // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     // it's not a number
        return 0;
    }   

    // check it's sign
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') { 
        d = c;
        if (!isdigit(c = getch())) {  // it's not a signed number
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return c;  
        }
    }   

    // collect its integer part
    for (*pf = 0; isdigit(c); c = getch())
        *pf = 10 * *pf + (c - '0');
    
    // collect its float part
    if (c == '.')
        c = getch();
    for (power = 1; isdigit(c); c = getch()) {
        *pf = 10 * *pf + (c - '0');
        power *= 10;
    }
    *pf = *pf * sign / power;

    if (c != EOF)
        ungetch(c);
    return c;
}

