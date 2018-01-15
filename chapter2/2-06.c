#include <stdio.h>

unsigned  getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

char setbits(unsigned x, int p, int n, unsigned y)
{
    return x - ((getbits(x, p, n) - getbits(y, n-1, n)) << (p+1-n));
}

main()
{
    unsigned x, y;
    x = 41;
    y = 7;
    int p, n;
    p = 4;
    n = 3;
    x = setbits(x, p, n, y);
    printf("%u\n", x);
    
}

