#include <stdio.h>
/* count digits, white space, others */
int main()
{
    int c, i;
    int ndigit[52] = {0};

    // recognize a character
    // record it in arry
    while ((c = getchar()) != EOF)
        if (c >= 'A' && c <= 'Z')
        {
            ++ndigit[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z')
        {
            ++ndigit[c - 'a' + 26];
        }

    for (i = 0; i < 26; i++)
    {
        printf("%c  %d\n", (char)i+65, ndigit[i]);
    }
    for (i = 26; i < 52; i++)
    {
        printf("%c  %d\n", (char)i+71, ndigit[i]);
    }
}