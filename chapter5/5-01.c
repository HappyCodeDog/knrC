#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, d;

    while (isspace(c = getch()))    // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     // it's not a number
        return 0;
    }
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
    *pn = 1;
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

main()
{
    int x = -1;
    int *pn = &x;   // remember to initialize the pointer
    getint(pn);
    printf("%d\n", *pn);
}

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                    printf("ungetch: too many characters\n");
                        else
                                    buf[bufp++] = c;
}

