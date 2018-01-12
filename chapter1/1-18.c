#include <stdio.h>
#define MAXLINE 30
#define MAXLINENUM 20

int getline(char s[]);
void copy(char to[], char from[]);
int isallblank(char s[]);

main() 
{
    char line[MAXLINE];
    char alllines[MAXLINENUM][MAXLINE];
    int j = 0;
 
    while (getline(line) > 0) 
        if (isallblank(line) == 0)
            copy(alllines[j++], line);

    for (int k = 0; k < j; k++)
        printf("%s", alllines[k]);
}


// trailing blanks and tabs will be removed
int getline(char s[])
{
    int c, i = 0;
    int inblank, intab;
    inblank = intab = 0;

    while ((c=getchar())!=EOF && c!='\n') {
        if (c == ' ') 
            if (inblank == 0)
                inblank = 1;
            else
                continue;
        else if (c == '\t')
            if (intab == 0)
                intab = 1;
            else
                continue;
        else 
            inblank = intab = 0;

        s[i++] = c;
    }
        
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int isallblank(char s[])  // 1 indicates this line is all blanks
{
    for (int i = 0; s[i] != '\n' && s[i] != '\0'; i++)
        if (s[i] != ' ')
            return 0;

    return 1;
}

void copy(char to[], char from[])                    
{
    for (int i = 0; (to[i] = from[i]) != EOF; i++)
        ;
}

