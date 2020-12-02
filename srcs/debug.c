#include "../head.h"

void    put_option(int *option)
{
    printf("\n--------option-------\n");
    printf("option[a] = %d\n", option[key('a')]);
    printf("option[l] = %d\n", option[key('l')]);
    printf("option[t] = %d\n", option[key('t')]);
    printf("option[R] = %d\n", option[key('R')]);
    printf("option[r] = %d\n", option[key('r')]);
    printf("---------------------\n\n");
}

void    put_dirname(char **dirname)
{
    printf("\n--------dirname-------\n");
    int i = 0;
    while (dirname[i])
    {
        printf("dirname[%d] = %s\n", i, dirname[i]);
        i++;
    }
    printf("----------------------\n\n");
}
