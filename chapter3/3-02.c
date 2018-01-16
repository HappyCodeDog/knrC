#include <stdio.h>
#define MAXWORD 50

/* converts newline and tab into visible escape sequences
   \n and \t as it copys the string t to s */
void escape(char s[], char t[])
{
    int i = 0, j;

    for (j = 0; t[j] != '\0'; ++j) 
        switch (t[j]) {
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                break;
            default:
                s[i++] = t[j];
                break;
        }
    s[i] = '\0';
}

void unescape(char s[], char t[])
{
    int i = 0, j;

    for (j = 0; t[j] != '\0'; ++j)
        if (t[j] == '\\')
            switch (t[++j]) {
                case 'n':
                    s[i++] = '\n';
                    break;
                case 't':
                    s[i++] = '\t';
                    break;
                default:
                    s[i++] = '\\';
                    s[i++] = t[j];
                    break;
            }
        else
            s[i++] = t[j];

    s[i] = '\0';
}

main()
{
    char s[MAXWORD], t[MAXWORD];
    fgets(t, MAXWORD, stdin);
    unescape(s, t);
    fputs(s, stdout);
}
