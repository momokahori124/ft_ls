#include "../head.h"

int     count_inner(char *dirname)
{
    int count = 0;
    DIR             *dir_ptr; 
    struct dirent   *direntp; 

    if ((dir_ptr = opendir(dirname)) == NULL)
    {
        ft_putstr("ls: ");
        ft_putstr(dirname);
        ft_putstr(": ");
        perror("");
        return (-1);
    }
    count = 0;
    while ((direntp = readdir(dir_ptr)) != NULL)
        count++;
    closedir(dir_ptr);
    return (count);
}

int    input_inner(char **inner_dirname, char *dirname)
{
    DIR             *dir_ptr; 
    struct dirent   *direntp; 

    if ((dir_ptr = opendir(dirname)) == NULL)
    {
        return (-1);
    }
    int i = 0;
    while ((direntp = readdir(dir_ptr)) != NULL)
    {
        inner_dirname[i] = ft_strdup(direntp->d_name);
        i++;
    }
    if (i == 0)
        return (-1);
    inner_dirname[i] = NULL;
    closedir(dir_ptr);
    return (0);
}

void    input_option(t_input *input, int ac, char *av[])
{
    int i;
    int j;
    if (!av[1])
        return ;

    i = 1;
    while (av[i])
    {
        if (av[i][0] != '-')
            break;
        j = 1;
        while (av[i][j])
        {
            if (av[i][j] != '-')
                input->option[key(av[i][j])] = 1;
            j++;
        }
        i++;
    }
}

void    input_dirname(char *av[], t_input *input)
{
    //ここでdirnameないときはカレントディレクトリを入れるようにしてくれる
    if (input->dirnum == 0)
    {
        input->dirname[0] = ft_strdup(".");
        input->dirname[1] = NULL;
        input->dirnum = 1;
        return ;
    }

    int i = 1;
    int count = 0;
    int flag = 0;
    while (av[i])
    {
        if (av[i][0] != '-')
            flag = 1;
        if (flag == 1 || av[i][0] != '-')
        {
            input->dirname[count] = ft_strdup(av[i]);
            count++;
        }
        i++;
    } 
    input->dirname[count] = NULL;
}

void    count_and_malloc_dirname(char *av[], t_input *input)
{
    int i;
    int flag;
    
    i = 1;
    flag = 0;
    while (av[i])
    {
        if (av[i][0] != '-')
        {
            flag = 1;
            input->dirnum++;
        }
        else if (flag == 1)
            input->dirnum++;
        i++;
    }  
    input->dirname = (char **)malloc(sizeof(char *) * (input->dirnum + 2));
}

int     main(int ac, char *av[])
{
    int i;
    char **dirname;
    int option[5];

    t_input input;
    input = (t_input){0};
    input_option(&input, ac, av);
    // put_option(input.option);
    count_and_malloc_dirname(av, &input);
    input_dirname(av, &input);
    // put_dirname(input.dirname);
    each_do_ls(input);
    return (0);

    // printf("%d\n", is_regfile("./srcs", "debug.o"));
}
