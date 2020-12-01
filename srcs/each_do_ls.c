
#include "../head.h"

void    convert_path(char *dirname, char **inner_dirname, char **path)
{
    int i;

    if (dirname[0] == '.')
    {
        i = 0;
        while (inner_dirname[i])
        {
            path[i] = inner_dirname[i];
            i++;
        }
        return;
    }
    i = 0;
    char *tmp;
    while (inner_dirname[i])
    {
        tmp = inner_dirname[i];
        path[i] = ft_strjoin3(dirname, inner_dirname[i]);
        free(tmp);
        i++;
    }
}


void    do_ls(char *dirname, t_input input, int index)
{

    printf("dirname : %s\n", dirname);

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
    convert_path(dirname, inner_dirname, path);
    sort_dirname(inner_dirname, input);
    if (dirname == NULL)
        return ;
    if (dirname[0] == '.' && index >= 1)
        return ;
    if (index >= 1 && input.option[key('R')] == 1)
    {
        // printf("------------\n");
        display_2D(dirname, inner_dirname, input);
        // printf("------------\n");
    }
    else
    {
        // printf("==========\n");
        display_2D(dirname, inner_dirname, input);
        // printf("==========\n");
    }
    index++;
    if (input.option[key('R')] == 1)
    {
        int i = 0;
        while (inner_dirname[i])
        {
            // printf("see : %s\n", inner_dirname[i]);
            //ここでディレクトリだけオープンしたい。
            if (inner_dirname[i][0] != '.')
            {
                tmp = inner_dirname[i];
                if (index >= 2)
                    tmp = ft_strjoin3(dirname, inner_dirname[i]);
                // printf("open : %s\n", tmp);
                if (is_directory(dirname, tmp) == 1)
                {
                    printf("%s %s\n", dirname, tmp);
                    do_ls(tmp, input, index);
                }
                if (index >= 2)
                    free(tmp);
            }
            i++;
        }
    }
}

void    each_do_ls(t_input input)
{
    int i = 0;
    int flag = 0;

    sort_dirname(input.dirname, input);
    if (input.dirnum > 1)
        flag = 1;
    i = 0;
    while (input.dirname[i])
    {
        if (flag == 1)
            printf("%s:\n", input.dirname[i]);
        do_ls(input.dirname[i], input, 0);
        if (flag == 1 && input.option[key('l')] != 1)
            printf("\n");
        if (i < input.dirnum - 1)
            printf("\n");
        i++;
    }
}
