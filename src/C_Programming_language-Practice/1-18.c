#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int my_getline(char line[], int maxline);
void delete_blank(char line[], int len);

int main()
{
    int len = 0;               /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0){

        delete_blank(line,len);
        
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

/* delete_blank: remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines*/
void delete_blank(char line[], int len){
    
    for(;len>0;--len){
        if(line[len - 1] != '\t' && line[len - 1] != ' '){
            break;
        }else{
            line[len - 1] = '\0';
        }
    }
}