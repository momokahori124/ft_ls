#include "../head.h"

void    ft_swap(char **s, char **t)
{
    char *tmp;

    tmp = *s;
    *s = *t;
    *t = tmp;
}

void    sort_by(char **dirname, int(*cmp_func)(char *, char *))
{
    int i;
    int j;

    i = 0;
    while (dirname[i])
    {
        j = 0;
        while (dirname[j])
        {
            if ((*cmp_func)(dirname[i], dirname[j]) < 0)
                ft_swap(&(dirname[i]), &(dirname[j]));
            j++;
        }
        i++;
    }     
}

void    sort_reverse(char **dirname)
{
    int count;
    int i;

    count = 0;
    while (dirname[count])
        count++;
    i = 0;
    while (i < count / 2)
    {
        ft_swap(&(dirname[i]), &(dirname[count - i - 1]));
        i++;
    }
}

void    sort_dirname(char **dirname, t_input input)
{
    sort_by(dirname, &(cmp_by_alpha));
    sort_by(dirname, &(cmp_by_mtime));//option-tがデフォルトなので
    sort_reverse(dirname);//option-rがデフォルトなので
    if (input.option[key('S')] == 1)
        sort_by(dirname, &(cmp_by_filesize));
    if (input.option[key('u')] == 1)
        sort_by(dirname, &(cmp_by_atime));
    if (input.option[key('U')] == 1)
        sort_by(dirname, &(cmp_by_ctime));
}
