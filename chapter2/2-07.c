#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p-n+1));
}

main()
{
    unsigned x = 21;
    int p = 3;
    int n = 3;
    x = invert(x, p, n);
    printf("%d\n", x);
}
