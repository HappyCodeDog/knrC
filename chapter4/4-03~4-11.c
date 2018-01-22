/* including    4-3: % and provisions for negative number 
 *              4-4: printtop, swaptop and clearstack
 *              4-5: library functions - sin, exp, pow
 *              4-6: 26 variables with single-letter names
 *              4-7: ungets(s)
 *              4-8: guarantee no more than 1 character of pushback
 *              4-9: handle a pushed-back EOF correctly
 *              4-10: use getline() to read an entire input line
 *              4-11: use an internal static variable in getop
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0'  // signal that a number was found
#define NAME 'n'    // signal that a name was found
#define BUFSIZE 100

int getop(char []);
int getch(void);
void ungetch(int c);
void ungets(char c[]);
void push(double);
double pop(void);
void clearstack(void);
void mathfunc(char s[]);
int getline(char s[], int lim);

/* reverse Polish calculator */
main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    double variables[26];   // use A~Z as variables names
    int var;
    for (int i = 0; i < 26; i++)    // initializer
        variables[i] = 0.0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':   // print the top element without poping
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'd':   // duplicate the top element in stack
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':   // swap the top two elements
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':
                clearstack();
                break;
            case NAME:
                mathfunc(s);
                break;
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    variables[var-'A'] = pop();
                else
                    printf("error: invalid variable name %c\n", var);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variables[type-'A']);
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
        var = type;
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clearstack(void)
{
    sp = 0;
}

//int i = 0;
//char line[MAXOP];

// 4-10: use getline() to read an entire input line
int getop(char s[])
{
    int c;
    // 4-11
    static int i = 0;
    static char line[MAXOP];
    if (i == 0) 
        if (getline(line, MAXOP) == 0)
            return EOF;
    
    while (line[i] == ' ' || line[i] == '\t')  // skip the blanks
        i++;

    int j = 0;
    while ((s[j] = c = line[i]) != '\n') {
        if (islower(c)) {   // math function or command
            while (islower(c = line[++i])) 
                s[++j] = c;
            
            s[++j] = '\0';
            if (strlen(s) > 1)  // math function
                return NAME;
            else 
                return c;   // command
        }
        else if (!isdigit(c) && c != '.')// signed number or operator
            if ((c == '+' || c == '-') && isdigit(line[i+1])) {
                c = line[++i];   // is a signed number
                s[1] = c;
                j = 1;
            }
            else {
                i++;
                return c;   // not a number
            }
        if (isdigit(c))  // collect integer part
            while (isdigit(c = line[++i])) 
                s[++j] = c;
        if (c == '.')   // collect fraction part
            while (isdigit(c = line[i++])) 
                s[++j] = c;
            
        s[++j] = '\0';
        return NUMBER;
    }
    i = 0;  // end of this line
    return '\n';
}
        
/*
int getop(char s[])
{
    int i = 0, c, next = -1;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (islower(c)) {   // math function or command
        while (islower(next = getch())) 
            s[++i] = next;
        s[++i] = '\0';
        if (next != EOF)
            ungetch(next);
        if (strlen(s) > 1)  // math function
            return NAME;
        else 
            return c;   // command
    }
    else if (!isdigit(c) && c != '.')   // signed number or operator
        if ((c == '+' || c == '-') && isdigit(next = getch())) {
            c = next;   // is a signed number
            s[1] = c;
            i = 1;
        }
        else {
            if (next == '\n')
                ungetch(next);
            return c;   // not a number
        }
    if (isdigit(c))  // collect integer part)
        while (isdigit(s[++i] = c = getch()))  
            ;
    if (c == '.')   // collect fraction part
        while (isdigit(s[++i] = c = getch()))  
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
*/

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* 4-8:
 int buf = 0;    // because usually 0 cannot be pushed back, so we 
                 // use 0 as sign of empty buffer
 
int getch(void)
{
    int c;

    if (buf == 0)
        c = getchar();
    else {
        c = buf; 
        buf = 0;
    }
    return c; 
}

void ungetch(int c)
{
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
*/

void ungets(char s[])
{
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

void mathfunc(char s[])
{
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        int op2 = pop();
        push(pow(pop(), op2));
    }
}


int getline(char s[], int lim)
{
    int c, i;

    i = 0; 
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
