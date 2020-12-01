#include "../head.h"

char *convert_time(char *t)
{
    char *ret;
    int i;
    int count;

    while (*t != ' ')
        t++;
    t++;
    ret = strdup(t);
    i = 0;
    count = 0;
    while (ret[i])
    {
        if (ret[i] == ':')
            count ++;
        if (count == 2)
        {
            ret[i] = '\0';
            break;
        }
        i++;
    }
    return (ret);
}

void    put_by_l(char *dirname, char *inner_dirname)  
{
    struct stat     stat_buf;
    struct passwd *user;
    struct group *group;
    char *time;
    char *tmp;

    if (dirname[0] != '.')
        tmp = ft_strjoin3(dirname, inner_dirname);
    else
        tmp = strdup(dirname);
    if (lstat(tmp, &stat_buf) == 0)
    {
        put_permission(stat_buf.st_mode);
        if (stat_buf.st_nlink > 1)
            printf("@");
        else
            printf(" ");
        printf("%2d ", stat_buf.st_nlink);//hardlink
        user = getpwuid(stat_buf.st_uid);
        group = getgrgid(stat_buf.st_gid);
        printf("%-6s", user->pw_name);
        printf("%6s", group->gr_name);
        printf("%7lld", stat_buf.st_size);
        time = convert_time(ctime(&stat_buf.st_mtime));
        printf(" %s ", time);
        printf("%s\n", inner_dirname);
    }
    else {
        perror("main ");
    }
    free(tmp);
}

void        put_by_option(char *dirname, char *inner_dirname, int *option)
{
    if (option[key('l')] == 1)
        put_by_l(dirname, inner_dirname);
    else
        printf("%-16s", inner_dirname);
}

void    put_block_size(char **dirname)
{
    int i;
    int res;
    struct stat     stat_buf;

    i = 0;
    res = 0;
    while (dirname[i])
    {
        stat(dirname[i], &stat_buf);
        res += stat_buf.st_blocks;
        i++;
    }    
    printf("total %d\n", res);
}

void    display_2D(char *dirname, char **inner_dirname, int *option)
{
    int     i;
    int     c;

    if (option[key('l')] == 1)
        put_block_size(inner_dirname);
    i = 0;
    while (inner_dirname[i])
    {
        if (inner_dirname[i][0] != '.' || option[key('a')] == 1)
            put_by_option(dirname, inner_dirname[i], option);
        i++;
        if (i % 7 == 0 && option[key('l')] == 0)
            printf("\n");
    }
}
