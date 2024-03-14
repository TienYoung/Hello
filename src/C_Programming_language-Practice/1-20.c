#include <stdio.h>
#include <string.h>

#define SPACE "  "   /* define n as a 2 space symbolic parameter */
#define MAXLINE 1000   /* maximum input line size */

int my_getline(char line[], int maxline);
void detab(char line[], int len, char to[]);
int main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    char to[MAXLINE] = {};      /* destation char arry */

    while ((len = my_getline(line, MAXLINE)) > 0){
            
            detab(line,len,to);
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

/* replaces tabs into n space */
void detab(char line[], int len, char to[]){
    int j = 0;
    for(int i = 0; i< len; i++){
        if(line[i] == '\t'){
            strcat(to, SPACE);
            j += strlen(SPACE);
            to[j+1] = '\0';/* strcat依赖于目标字符串是一个以`\0`结尾的有效的C字符串。
            如果`to`数组没有被正确地初始化为一个以`\0`结尾的字符串，
            `strcat`就会继续在`to`中查找`\0`直到找到为止，
            这可能会越过数组的边界，导致不可预测的行为，包括奇怪的字符输出。 */
        }else{
            to[j] = line[i];
            to[j+1] = '\0';
            j++;
        }
        
    }
}