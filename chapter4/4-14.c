#include <stdio.h>
#define swap(t, x, y) { t temp = x; x = y; y = temp;}

main()
{
    int x, y;
    x = 2;
    y = 3;
    swap(int, x, y);
    printf("%d, %d\n", x, y);
}
