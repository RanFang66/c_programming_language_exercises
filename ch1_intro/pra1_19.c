#include    <stdio.h>
#define     MAXLINE  1000

int my_getline(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];

    while(my_getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

int my_getline(char s[], int lim)
{
    int c;
    int i;
    int j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim-2) {
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

void reverse(char s[])
{
    int i;
    int j;
    char temp;

    j = 0;
    while (s[j] != '\0') {
        j++;
    }
    j--;

    if (s[j] == '\n') {
        j--;
    }

    i = 0;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
}