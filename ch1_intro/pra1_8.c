#include <stdio.h>

#define     IN      1
#define     OUT     0

int main(void)
{
    int c;
    int nl, nt, nb;

    nl = nt = nb = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nl++;
        else
            continue;
    }
    printf("nb=%d, nt=%d, nl=%d\n", nb, nt, nl);
    return 0;
}
