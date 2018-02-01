#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXVAL 100
#define MAXOP 100

void push(int);
int pop(void);

main(int argc, char *argv[])
{
    char s[MAXOP];
    int c, op2, i, j;

    //argv++; // skip the program name("expr")
    for (i = 1; --argc > 0; i++) 
        while (c = *argv[i]++)
            if (isdigit(c)) {   // is an operand
                j = 0;
                s[j++] = c;
                while (isdigit(c = *argv[i]+1)) {
                    s[j++] = c;
                    (*argv[i])++;
                }
                s[j] = '\0';
                push(atoi(s));
            }
            else                // is an operator
                switch (c) {
                    case '+':
                        push(pop() + pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    // '*' is the wildcard in linux shell, so use 
                    // "\*" in argument to unescape 
                    case '*':
                        push(pop() * pop());
                        break;
                    case '/':
                        op2 = pop();
                        push(pop() / op2);
                        break;
                    default:
                        printf("error: invalid parameters!\n");
                        break;
                }
    printf("%d\n", pop());
}


int sp = 0;
int val[MAXVAL];

void push(int n)
{
    if (sp < MAXVAL)
        val[sp++] = n;
    else
        printf("error: full stack!\n");
}

int pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: empty stack!\n");
        return -1;
    }
}
