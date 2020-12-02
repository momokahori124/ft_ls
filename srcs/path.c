#include "../head.h"

char    *path_to_filename(char *s)
{
    char *ret;

    if (s == NULL)
    {
        ft_putstr("somthing wrong with path_to_filename\n");
        return (NULL);
    }
    int len = ft_strlen(s);
    int i = len - 1;
    while (i >= 0)
    {
        if (s[i] == '/')
        {
            ret  = ft_strdup(s + i + 1);
            return (ret);
        }
        i--;
    }
    ret = ft_strdup(s);
    return (ret);
}

void    convert_path(char *dirname, char **inner_dirname, char ***path)
{
    int i;
    
    i = 0;
    while (inner_dirname[i])
        i++;
    (*path) = malloc(sizeof(char *) * (i + 1));

    if (dirname[0] == '.' && dirname[1] != '/')
    {
        i = 0;
        while (inner_dirname[i])
        {
            (*path)[i] = ft_strdup(inner_dirname[i]);
            i++;
        }
        (*path)[i] = NULL;
        return;
    }
    i = 0;
    while (inner_dirname[i])
    {
        (*path)[i] = ft_strjoin3(dirname, inner_dirname[i]);
        i++;
    }
    (*path)[i] = NULL;
}

void    path_to_filename_2D(char ***s)
{
    int i = 0;
    char *tmp;

    while ((*s)[i])
    {
        tmp = (*s)[i];
        (*s)[i] = path_to_filename((*s)[i]);
        free(tmp);
        i++;
    }   
}

