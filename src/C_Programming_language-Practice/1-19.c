#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int my_getline(char line[], int maxline);
void reverse(char line[], int len, char destation[]);

int main()
{
    int len = 0;               /* current line length */
    char line[MAXLINE];    /* current input line */
    char destation[MAXLINE]; /* reverse  line */

    while ((len = my_getline(line, MAXLINE)) > 0){
        
        reverse(line,len,destation);
        printf("%s", destation);
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

/* reverse: reverses the character string */
void reverse(char line[], int len, char destation[]){

    for(int i = 0;len>0;--len){
        destation[i] = line[len - 1];
        i++ ;
    }
}