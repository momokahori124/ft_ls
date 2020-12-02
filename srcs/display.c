#include "../head.h"

char *convert_time(char *t)
{
    char *ret;
    int i;
    int count;

    while (*t != ' ')
        t++;
    t++;
    ret = ft_strdup(t);
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

void    put_by_l(char *dirname, char *inner_dirname, t_input input)  
{
    struct stat     stat_buf;
    struct passwd *user;
    struct group *group;
    char *time;
    char *tmp;

    if (dirname[0] != '.')
        tmp = ft_strjoin3(dirname, inner_dirname);
    else
        tmp = ft_strdup(inner_dirname);
    if (lstat(tmp, &stat_buf) == 0)
    {
        put_permission(stat_buf.st_mode);
        if (stat_buf.st_nlink > 1)
            printf("@");
        else
            printf(" ");
        printf(" %2d ", stat_buf.st_nlink);//hardlink
        user = getpwuid(stat_buf.st_uid);
        group = getgrgid(stat_buf.st_gid);
        printf("%-6s", user->pw_name);
        printf("%7s", group->gr_name);
        printf("%7lld", stat_buf.st_size);
        time = convert_time(ctime(&stat_buf.st_mtime));
        if (input.option[key('u')] == 1)
            time = convert_time(ctime(&stat_buf.st_atime));
        if (input.option[key('U')] == 1)
            time = convert_time(ctime(&stat_buf.st_ctime));
        printf(" %s ", time);
        printf("%s", inner_dirname);
        if (S_ISLNK(stat_buf.st_mode) == 1)
        {
            char buf[255];
            readlink(tmp, buf, 255);
            printf(" -> %s", buf);
        }
        printf("\n");
    }
    else
        perror("put_by_l : ");
    free(tmp);
}

void        put_by_option(char *dirname, char *inner_dirname, t_input input)
{
    struct stat     buf;	

    lstat(inner_dirname, &buf);
    if (input.option[key('s')] == 1)
        printf("%3lld ", buf.st_blocks);
    if (input.option[key('l')] == 1)
        put_by_l(dirname, inner_dirname, input);
    else
        printf("%s\n", inner_dirname);
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

void    display_2D(char *dirname, char **inner_dirname, t_input input)
{
    int     i;
    int     c;

    if (input.option[key('l')] == 1)
        put_block_size(inner_dirname);
    i = 0;
    while (inner_dirname[i])
    {
        if (inner_dirname[i][0] != '.' || input.option[key('a')] == 1)
            put_by_option(dirname, inner_dirname[i], input);
        i++;
    }
}
