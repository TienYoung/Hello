#include <stdio.h>
/* count digits, white space, others */
int main()
{
    int c, i,state,cw;
    int ndigit[50] = {0};
    #define  OUT 0
    #define IN 1
    // recognize a word 
    // record the length of the word in arry
    state = OUT;
    cw = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            ++ndigit[cw];
            cw = 0;
            cw++;
        }else if(state == IN){
            cw++;
        }

    for(i = 0; i < 50; i++){
        printf("%d  %d\n",i,ndigit[i]);
    }

}
