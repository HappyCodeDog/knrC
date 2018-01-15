#include <stdio.h>

/* return the bit width of x */
int width(unsigned x)
{
    int w, d;
    w = 0;
    d = 1;

    while (x / d >= 1) {
        w++;
        d *= 2;
    }

    return w;
}

unsigned rightrot(unsigned x, int n)
{
    int w = width(x);
    for (int i = 0; i < n; ++i) 
        x = ((x & 1) << (w - 1)) | (x >> 1);
    return x;
}

main()
{
    unsigned x = 21;
    int n = 2;
    printf("%u\n", rightrot(x, n));
}
