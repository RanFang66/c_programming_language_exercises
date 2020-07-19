#include <stdio.h>

#define     LOWER       0
#define     UPPER       300
#define     STEP        20

int main(void)
{
    float fahr, celsius;

    printf("*** Fahrenheit-Censius Table ***\n");
    printf("Fahrenheit | Celsius\n");

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.0f     | %6.1f\n", fahr, celsius);
    }
    return 0;
}
