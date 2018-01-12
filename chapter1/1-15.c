#include <stdio.h>

void FtoC(float lower, float upper, float step);

main() 
{
    FtoC(0, 300, 20);
}

void FtoC(float lower, float upper, float step)
{
    float fahr, celsius;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}
