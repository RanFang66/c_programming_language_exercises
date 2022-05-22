#include <stdio.h>

#define     MAXLINE     1000
#define     LONGLINE    80


int my_getline(char line[], int maxline);

int main(void)
{
    char line[MAXLINE];
    int  len;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > LONGLINE) {
            printf("%d : %s", len, line);
        }
    }

    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;
    int j = 0;
    
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 2) {
            s[j] = c;
            j++;
        }
    }

    if (c == '\n') {
        s[j++] = '\n';
        i++;
    }

    s[j] = '\0';

    return i;
}
