#include <stdio.h>
#define ALPHANUMBER 52

main() 
{
    int c;
    int counts[ALPHANUMBER];

    for (int i = 0; i < ALPHANUMBER; i++) 
        counts[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= 'A' && c <= 'z') 
            counts[c-'A']++;

    for (int i = 0; i < ALPHANUMBER; i++) {
        if (counts[i] > 0) {
            putchar('A'+i);
            printf(" |");
            for (int j = 0; j < counts[i]; j++)
                putchar('=');
            printf(" %d\n", counts[i]);
        }
    }
}
