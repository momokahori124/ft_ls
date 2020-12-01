#include "../head.h"

int     sort_func(char *s, char *t)
{
    int i;

    i = 0;
    while (s[i] && t[i])
    {
        if (s[i] != t[i])
            return (s[i] - t[i]);
        i++;
    }
    return (s[i] - t[i]);
}

void    sort_dirname(char **dirname)
{
    int i;
    int j;
    char *tmp;

    if (!dirname)
        return ;

    i = 0;
    while (dirname[i])
    {
        j = 0;
        while (dirname[j])
        {
            if (sort_func(dirname[i], dirname[j]) < 0)
            {
                tmp = dirname[i];
                dirname[i] = dirname[j];
                dirname[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
