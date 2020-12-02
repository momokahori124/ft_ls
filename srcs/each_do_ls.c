
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
    path = (char **)malloc(sizeof(char *) * (count + 1));
    input_inner(inner_dirname, dirname);
    sort_dirname(dirname, inner_dirname, input);
    if (dirname == NULL)
        return ;
    display_2D(dirname, inner_dirname, input);
}

/*
    inner_dirnameを出力する　→　
*/

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
    if (dirname == NULL)
        return ;

    if (index > 0)
        printf("\n%s:\n", dirname);
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

    // sort_dirname(input.dirname, input);
    sort_by(input.dirname, &(cmp_by_alpha));
    if (input.dirnum > 1)
        flag = 1;
    i = 0;
    while (input.dirname[i])
    {
        if (flag == 1)
            printf("%s:\n", input.dirname[i]);
        do_ls(input.dirname[i], input);
        if (flag == 1 && input.option[key('l')] != 1)
            printf("\n");
        if (i < input.dirnum - 1)
            printf("\n");
        i++;
    }
}
