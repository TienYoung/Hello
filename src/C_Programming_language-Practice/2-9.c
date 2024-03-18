#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int bitcount(unsigned x);

int main(void)
{


    unsigned x = 8;
    
    printf("%d", bitcount(x));
    printf("\n");

    return 0;
}

/* bitcount: count how many 1 bits there in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x - 1))
            b++;
    return b;
}