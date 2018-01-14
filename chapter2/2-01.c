#include <limits.h>
#include <stdio.h>

main() 
{
    printf("char: %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d ~ %d\n", INT_MIN, INT_MAX);
    printf("long: %d ~ %d\n", LONG_MIN, LONG_MAX);
    printf("\n");
    printf("unsigned char max: %u\n", (unsigned char)~0);
    printf("unsigned int max: %u\n", (unsigned int)~0);
    printf("unsigned long max: %u\n", (unsigned long)~0);
    printf("\n");
    printf("signed char max: %d\n", (unsigned char)~0 >> 1);
    char i = (unsigned char)~0 ^ ((unsigned char)~0 >> 1);
    printf("signed char min: %d\n", i);

    
}
