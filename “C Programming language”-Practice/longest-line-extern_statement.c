#include <stdio.h>
#define MAXLINE 1000   /* maximum input line size */
int max;               /* maximum length seen so far */
char line[MAXLINE];    /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int my_getline(void);
void copy(void);
/* print longest input line; specialized version */
int main(void)
{
    int len;
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = my_getline()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}
/* my_getline: specialized version */
int my_getline(void)
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF &&c != '\n'; ++i){
        line[i] = c;    
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
/* copy: specialized version */
void copy(void)
{
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
/*But external variables are always there even when you don't want them. 
Relying too heavily on external variables is fraught with peril 
since it leads to programs whose data connections are not all obvious
 - variables can be changed in unexpected and even inadvertent ways, 
 and the program is hard to modify. 
 The second version of the longest-line program is inferior to the first, 
 partly for these reasons, and partly because it destroys 
 the generality of two useful functions by writing into them 
 the names of the variables they manipulate.*/