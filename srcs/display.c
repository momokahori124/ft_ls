#include "../head.h"

void        put_by_option(char *dirname, char *inner_dirname, t_input input)
{
    struct stat     buf;	

    lstat(inner_dirname, &buf);
    if (input.option[key('s')] == 1)
        ft_printf_d("% ", 3, buf.st_blocks);
    ft_put_dirname(dirname, inner_dirname, input);
}

void    put_block_size(char **dirname, t_input input)
{
    int i;
    int res;
    struct stat     stat_buf;

    i = 0;
    res = 0;
    while (dirname[i])
    {
        if (dirname[i][0] == '.' && input.option[key('a')])
            res += stat_buf.st_blocks;
        else if (dirname[i][0] == '.' && dirname[i][1] == '/')
            res += stat_buf.st_blocks;
        else if (dirname[i][0] == '.')
            ;
        else if (lstat(dirname[i], &stat_buf) == 0)
            res += stat_buf.st_blocks;
        i++;
    }    
    ft_printf_d("total %\n", 0, res);
}


void    display_2D(char *dirname, char **inner_dirname, t_input input)
{
    int     i;
    int     c;

    if (input.option[key('s')])
        put_block_size(inner_dirname, input);

    i = 0;
    while (inner_dirname[i])
    {
        if (inner_dirname[i][0] != '.' || input.option[key('a')] == 1)
            put_by_option(dirname, inner_dirname[i], input);
        i++;
    }
}
