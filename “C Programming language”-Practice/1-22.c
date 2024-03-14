#include <stdio.h>
#include <string.h>

#define N 9   /* fold each 9 char */
#define MAXLINE 1000   /* maximum input line size */

int my_getline(char line[], int maxline);
void fold(char line[], int len, char to[]);
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    char to[MAXLINE] = {};      /* destation char arry */

    while ((len = my_getline(line, MAXLINE)) > 0){
            
            fold(line,len,to);
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

/*  fold: ``fold'' long input lines into two or more shorter lines after the last non-blank character 
that occurs before the n-th column of input.*/
void fold(char line[], int len, char to[]){
    int j = 0;
    for(int i = 0; i < len; i++){
        if(i % N == 0){
            for(int l = N; l > 0; l--){
                if(l != ' ' && l != '\t'){
                    to[j- (N - l)] = '\n';
                    j = j- (N - l) + 1;
                    break;
                }
            }            
        }else{
            to[j] = line[i];
            j++;
        }
    }
}
