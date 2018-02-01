#include <stdio.h>
#include <string.h>

/* strend(s, t) returns 1 if the string t occurs at the end of 
 * string s, and 0 otherwise.
 */
int strend(char s[], char t[])
{
    int s_len, t_len;
    s_len = strlen(s);
    t_len = strlen(t);
    
    if (s_len < t_len)
        return 0;

    s += (s_len - t_len);
    while ((*s != '\0') && (*s++ == *t++))
        ;
    if (*s) 
        return 0;
    else 
        return 1;
}

main()
{
    char s[20];
    char t[20];
    printf("string s: ");
    fgets(s, 20, stdin);
    printf("string t: ");
    fgets(t, 20, stdin);
    printf("%d\n", strend(s, t));
}
