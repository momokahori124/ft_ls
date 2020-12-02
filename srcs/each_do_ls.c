
#include "../head.h"

void    no_option_R(char *dirname, t_input input)
{
    DIR             *dir_ptr; 
    struct dirent   *direntp; 
    char            **inner_dirname;
    int             count;
    char            *tmp;
    char **path;

    if ((count = count_inner(dirname)) == -1)
        return ;
    inner_dirname = (char **)malloc(sizeof(char *) * (count + 1));
    input_inner(inner_dirname, dirname);
    sort_dirname(dirname, inner_dirname, input);
    if (dirname == NULL)
        return ;
    display_2D(dirname, inner_dirname, input);
    free_2D(&inner_dirname);
}

void    option_R(char *dirname, t_input input, int index)
{
    DIR             *dir_ptr; 
    struct dirent   *direntp; 
    char            **inner_dirname;
    int             count;
    char            *tmp;
    char **path;

    if ((count = count_inner(dirname)) == -1)
        return ;
    inner_dirname = (char **)malloc(sizeof(char *) * (count + 1));
    input_inner(inner_dirname, dirname);
    sort_dirname(dirname, inner_dirname, input);
    if (index > 0)
        ft_printf_s("\n%:\n", 0, dirname);
    display_2D(dirname, inner_dirname, input);
    int i = 0;
    while (inner_dirname[i])
    {
        if (is_directory(dirname, inner_dirname[i]) == 1 && inner_dirname[i][0] != '.')
        {
            tmp = dirname;
            tmp = ft_strjoin3(dirname, inner_dirname[i]);
            option_R(tmp, input, index + 1);
            free(tmp);
        }
        i++;
    }
    free_2D(&inner_dirname);
}

void    do_ls(char *dirname, t_input input)
{
    if (input.option[key('R')] == 1)
    {
        option_R(dirname, input, 0);
        return ;
    }
    no_option_R(dirname, input);
}

void    each_do_ls(t_input input)
{
    int i = 0;
    int flag = 0;

    sort_dirname(".", input.dirname, input);
    if (input.dirnum > 1)
        flag = 1;
    i = 0;
    while (input.dirname[i])
    {
        if (flag == 1)
            ft_printf_s("%:\n", 0, input.dirname[i]);
        do_ls(input.dirname[i], input);
        if (flag == 1 && input.option[key('R')] != 1)
            ft_putstr("\n");
        if (i < input.dirnum - 1)
            ft_putstr("\n");
        i++;
    }
}
