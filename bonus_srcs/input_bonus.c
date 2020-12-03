/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:17:14 by mhori             #+#    #+#             */
/*   Updated: 2020/12/04 04:48:41 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		count_inner(char *dirname)
{
	int				count;
	DIR				*dir_ptr;
	struct dirent	*direntp;

	count = 0;
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

int		input_inner(char **inner_dirname, char *dirname)
{
	DIR				*dir_ptr;
	struct dirent	*direntp;
	int				i;

	if ((dir_ptr = opendir(dirname)) == NULL)
		return (-1);
	i = 0;
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

void	input_option(t_input *input, int ac, char *av[])
{
	int		i;
	int		j;

	if (!av[1])
		return ;
	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-')
			break ;
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] != '-')
			{
				input->option[key(av[i][j])] = 1;
				if (av[i][j] == 'u' || av[i][j] == 'U')
					input->u = av[i][j];
			}
			j++;
		}
		i++;
	}
}

void	if_dirnum_one(t_input *input)
{
	input->dirname[0] = ft_strdup(".");
	input->dirname[1] = NULL;
	input->dirnum = 1;
}

void	input_dirname(char *av[], t_input *input)
{
	int	i;
	int	count;
	int	flag;

	if (input->dirnum == 0)
	{
		if_dirnum_one(input);
		return ;
	}
	i = 1;
	count = 0;
	flag = 0;
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
