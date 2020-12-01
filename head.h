#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

typedef struct s_input
{
    int     option[6];
    int     dirnum;
    char    **dirname;
}               t_input;

void    sort_dirname(char **dirname);
void    ft_swap(char **s, char **t);
void    display_2D(char *dirname, char **inner_dirname, int *option);
void    ft_putstr(char *s);
int    key(char c);
char    *ft_strjoin3(char *s, char *t);
int     count_inner(char *dirname);
int    input_inner(char **inner_dirname, char *dirname);
void    put_permission(int per);

/* each_do_ls.c */
void    do_ls(char *dirname, int *option, int index);
void    each_do_ls(t_input input);

/* debug.c */
void    put_option(int *option);
void    put_dirname(char **dirname);

#endif