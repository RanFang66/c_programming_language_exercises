#include <stdio.h>

int main(void)
{
    int c;
    int last_c;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || last_c != ' ')
            putchar(c);
        last_c = c;
    }
    return 0;
}
