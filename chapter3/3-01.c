/* a recursive version of binsearch */
#include <stdio.h>

int binsearch(int x, int v[], int low, int high)
{
    int mid = (low + high) / 2;
    if (v[mid] == x)
        return mid;

    while (low <= high) 
        if (x < v[mid])
            return binsearch(x, v, low, mid-1);
        else
            return binsearch(x, v, mid+1, high);

    return -1; // no match
}

main()
{
    int v[] = {1, 12, 17, 25, 44, 61, 88, 97, 99, 100};
    int x = 17;
    printf("%d\n", binsearch(x, v, 0, 9));
}
