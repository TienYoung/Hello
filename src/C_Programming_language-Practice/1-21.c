#include <stdio.h>
#include <string.h>

#define MAXLINE 1000   /* maximum input line size */

int my_getline(char line[], int maxline);
void entab(char line[], int len, char to[]);
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    char to[MAXLINE] = {};      /* destation char arry */

    while ((len = my_getline(line, MAXLINE)) > 0){
            
            entab(line,len,to);
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

/*  entab: replaces strings of blanks by the minimum number of 
tabs and blanks to achieve the same spacing*/
void entab(char line[], int len, char to[]){
    int j = 0;
    int state = 0;
    for(int i = 0; i< len; i++){
        if(line[i] != ' ' && state == 0){
            to[j] = line[i];
            j++;
        }else if (line[i] != ' ' && state == 1){
            to[j] = ' ';
            to[j + 1] = line[i];
            j += 2;
        }else if (line[i] == ' ' && state == 1){
            to[j] = '\t';
            j++;
            state = 0;
        }else if (line[i] == ' ' && state == 0){
            state = 1;
        }
    }
}
