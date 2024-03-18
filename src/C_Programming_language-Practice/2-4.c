#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

void squeeze(char* s1,char* s2);

int main(void){

    char s1[50] = "adlkfajhlauifdyalffdjhaliu";
    char s2[50] = "akd";
    squeeze(s1,s2);
    printf("%s",s1);
    printf("\n");

    return 0;
}

/* squeeze: deletes each character in s1 
that matches any character in the string s2 */
void squeeze(char* s1,char* s2){
    int i, j;
    int l = 0;
    
    for(i = 0; s1[i] != '\0'; i++){
        int shouldDelete = 0;
        for(j = 0; s2[j]; j++){
            if(s1[i] == s2[j]){
                shouldDelete = 1;
                break;
            }
        }
       if(!shouldDelete){
         s1[l++] = s1[i];
       } 
    }
}