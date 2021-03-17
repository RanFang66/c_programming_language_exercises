#include <stdio.h>

float celsius(float fahr);

int main(void)
{   
    float   fahr;
    int     lower, upper, step;

    lower = -100;
    upper = 300;
    step  = 20;

    printf("cels   fahr\n");
    for (fahr = lower; fahr <= upper; fahr += step) {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
    }

    return 0;
}

float celsius(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
