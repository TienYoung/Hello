#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int my_getline(char line[], int maxline);
void removeAllComments(char line[], int len, char to[]);

#define MAXLINE 1000   /* maximum input line size */

int main(void){

    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    char to[MAXLINE] = {};      /* destation char arry */

    while((len = (my_getline(line, MAXLINE))) > 0){
        removeAllComments(line,len,to);
        printf("%s", to);
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

void removeAllComments(char line[], int len, char to[]){
    int i = 0;
    int j = 0;
    int inComment = 0;
    for(i; i < len; i++){
        if(line[i] == '/' && line[i + 1] == '*'){
            i++;
            inComment = 1;
        }else if (line[i] == '*' && line[i + 1] == '/'){
            i++;
            inComment = 0;
        }
        if(inComment == 0 &&  line[i] != '/'){
            to[j] = line[i];
            j++;
        }
    }
}
