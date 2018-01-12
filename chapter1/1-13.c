#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define MAXLENGTH 10    // max length of a word

main() 
{
    char words[MAXWORD][MAXLENGTH];   // array of words in its input
    int lengths[MAXWORD];   // length of each word in its input
    int c, i = 0;   // i indicates the index of the two arrays above
    int wl = 0; // wl indicates the length of the current word
    int newword = 0;
    char cw[MAXLENGTH] = "";  // current word

    while ((c = getchar()) != EOF) {

        if (c >= 'A' && c <= 'z') {
            newword = 1;
            cw[wl++] = c;
            //putchar(cw[wl-]);
        }
        else if (newword == 1) {
            newword = 0;
            cw[wl] = '\0';
            strcpy(words[i], cw);
            lengths[i] = wl;
            i++;
            wl = 0;
        }
    }

    // vertical histogram
    for (int m = 0; m < MAXLENGTH+1; m++) {
        for (int n = 0; n < i; n++) {
            if (m < MAXLENGTH-lengths[n])
                putchar(' ');
            else if (m == MAXLENGTH-lengths[n])
                printf("%d", lengths[n]);
            else 
                putchar('*');

            if (n == i-1)
                printf("\n");
        }
    }

    for (int n = 0; n < i; n++) 
        putchar('1'+n);

    /* horizontal histogram
    for (int j = 0; j < i; j++) {
        printf("%15s|", words[j]);
        for (int k = 0; k < lengths[j]; k++)
           putchar('=');
        printf("| %d\n", lengths[j]);     
    }
    */
}
