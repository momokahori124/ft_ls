
#include "../head.h"


void    do_ls(char *dirname, int *option, int index)
{
    DIR             *dir_ptr; 
    struct dirent   *direntp; 
    char            **inner_dirname;
    int             count;
    char            *tmp;

    if ((count = count_inner(dirname)) == -1)
        return ;
    inner_dirname = (char **)malloc(sizeof(char *) * (count + 1));
    input_inner(inner_dirname, dirname);
    sort_dirname(inner_dirname);
    if (dirname == NULL)
        return ;
    if (dirname[0] == '.' && index >= 1)
        return ;
    if (index >= 1 && option[key('R')] == 1)
        display_2D(dirname, inner_dirname, option);
    else
        display_2D(dirname, inner_dirname, option);
    index++;
    if (option[key('R')] == 1)
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
                do_ls(tmp, option, index);
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

    sort_dirname(input.dirname);
    if (input.dirnum > 1)
        flag = 1;
    i = 0;
    while (input.dirname[i])
    {
        if (flag == 1)
            printf("%s:\n", input.dirname[i]);
        do_ls(input.dirname[i], input.option, 0);
        if (flag == 1 && input.option[key('l')] != 1)
            printf("\n");
        if (i < input.dirnum - 1)
            printf("\n");
        i++;
    }
}
