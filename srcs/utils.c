#include "../head.h"

void    ft_putstr(char *s)
{
    if (!s)
        return ;
    while (*s)
    {
        write(1, s, 1);
        s++;
    }
}

int    key(char c)
{
    if (c == 'l')
        return (0);
    else if (c == 'a')
        return (1);
    else if (c == 'R')
        return (2);
    else if (c == 'r')
        return (3);
    else if (c == 't')
        return (4);
    return (5);
}

char    *ft_strjoin3(char *s, char *t)
{
    int len = strlen(s) + strlen(t) + 10;
    char *ret = (char *)malloc(sizeof(char) * len);
    int i = 0;
    while (s[i])
    {
        ret[i] = s[i];
        i++;
    }
    ret[i] = '/';
    i++;
    int j = 0;
    while (t[j])
    {
        ret[i + j] = t[j];
        j++;
    }
    ret[i + j] = '\0';
    return (ret);
}
