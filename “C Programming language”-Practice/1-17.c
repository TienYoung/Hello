#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int my_getline(char line[], int maxline);

int main()
{
    int len = 0;               /* current line length */
    int max = 80;              
    char line[MAXLINE];    /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            printf("%s", line);
        }
        
    return 0;
}
/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
