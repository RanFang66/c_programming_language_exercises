#include <stdio.h>

#define     LOWER       -40
#define     UPPER       150
#define     STEP        10

int main(void)
{
    float fahr, celsius;

    printf("*** Censius-Fahrenheit Table ***\n");
    printf("Celsius Fahrenheit\n");

    celsius = LOWER;
    while (celsius <= UPPER) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%4.0f\t%6.1f\n", celsius, fahr);
        celsius += STEP;
    }
    return 0;
}
