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


void    sort_dirname(char *dirname, char **inner_dirname, t_input input)
{ 
    char **tmp;
    char *tp;
    tmp = inner_dirname;


    convert_path(dirname, inner_dirname, inner_dirname);
    sort_by(inner_dirname, &(cmp_by_mtime));//option-tがデフォルトなので
    if (input.option[key('S')] == 1)
        sort_by(inner_dirname, &(cmp_by_filesize));
    if (input.option[key('u')] == 1)
        sort_by(inner_dirname, &(cmp_by_atime));
    if (input.option[key('U')] == 1)
        sort_by(inner_dirname, &(cmp_by_ctime));

    sort_reverse(inner_dirname);//option-rがデフォルトなので

    int i = 0;
    while (inner_dirname[i])
    {
        tp = inner_dirname[i];
        inner_dirname[i] = path_to_filename(inner_dirname[i]);
        free(tp);
        i++;
    }
}
