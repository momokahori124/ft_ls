#include "../head.h"

void        put_by_option(char *dirname, char *inner_dirname, t_input input)
{
    struct stat     buf;	

    lstat(inner_dirname, &buf);
    if (input.option[key('s')] == 1)
        printf("%3lld ", buf.st_blocks);
    printf("%s\n", inner_dirname);
}

void    display_2D(char *dirname, char **inner_dirname, t_input input)
{
    int     i;
    int     c;

    i = 0;
    while (inner_dirname[i])
    {
        if (inner_dirname[i][0] != '.' || input.option[key('a')] == 1)
            put_by_option(dirname, inner_dirname[i], input);
        i++;
    }
}
