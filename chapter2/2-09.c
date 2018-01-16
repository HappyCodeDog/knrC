/* a faster version of bitcount */
#include <stdio.h>

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        ++b;

    return b;
}

main()
{
    int x = 21;
    printf("%d\n", bitcount(x));
}
