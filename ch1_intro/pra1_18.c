#include <stdio.h>

#define MAXLINE     1000

int my_getline(char line[], int maxline);
int remove_blank(char line[]);

int main(void)
{
    char line[MAXLINE];
    int  len;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (remove_blank(line) > 0) {
            printf("%s", line);
        }
    }
    return 0;
}

int my_getline(char s[], int lim)
{
    int c;
    int i;
    int j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 2) {
            s[j] = c;
            j++;
        }
    }

    if (c == '\n') {
        s[j] = c;
        j++;
        i++;
    }

    s[j] = '\0';
    
    return i;
}

int remove_blank(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\n') {
        i++;
    }

    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        i--;
    }
    
    if (i >= 0) {
        i++;
        s[i] = '\n';
        i++;
        s[i] = '\0';
    }

    return i;
}
