#include <stdio.h>

main()
{
    int blanks, tabs, newlines;
    blanks = tabs = newlines = 0;

    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newlines;
    }

    printf("\n");
    printf("blanks:%d\n", blanks);
    printf("tabs:%d\n", tabs);
    printf("newlines:%d\n", newlines);
}
