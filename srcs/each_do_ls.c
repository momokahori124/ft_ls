/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   each_do_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:58:48 by momoka            #+#    #+#             */
/*   Updated: 2020/12/03 22:49:53 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	no_option_r(char *dirname, t_input input)
{
	char			**inner_dirname;
	int				count;
	char			*tmp;
	char			**path;

	if ((count = count_inner(dirname)) == -1)
		return ;
	inner_dirname = (char **)malloc(sizeof(char *) * (count + 1));
	input_inner(inner_dirname, dirname);
	sort_dirname(dirname, inner_dirname, input);
	if (dirname == NULL)
		return ;
	display_2d(dirname, inner_dirname, input);
	free_2d(&inner_dirname);
}

void	option_r_sub(char *dirname, char *s, int index, t_input input)
{
	char			*tmp;

	if (is_directory(dirname, s) == 1 &&\
		s[0] != '.')
	{
		tmp = dirname;
		tmp = ft_strjoin3(dirname, s);
		option_r(tmp, input, index + 1);
		free(tmp);
	}
}

void	option_r(char *dirname, t_input input, int index)
{
	char			**inner_dirname;
	int				count;
	char			**path;
	int				i;

	if ((count = count_inner(dirname)) == -1)
		return ;
	inner_dirname = (char **)malloc(sizeof(char *) * (count + 1));
	input_inner(inner_dirname, dirname);
	sort_dirname(dirname, inner_dirname, input);
	if (index > 0)
		ft_printf_s("\n%:\n", 0, dirname);
	display_2d(dirname, inner_dirname, input);
	i = 0;
	while (inner_dirname[i])
	{
		option_r_sub(dirname, inner_dirname[i], index, input);
		i++;
	}
	free_2d(&inner_dirname);
}

void	do_ls(char *dirname, t_input input)
{
	if (input.option[key('R')] == 1)
	{
		option_r(dirname, input, 0);
		return ;
	}
	no_option_r(dirname, input);
}

void	each_do_ls(t_input input)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	sort_dirname(".", input.dirname, input);
	if (input.dirnum > 1)
		flag = 1;
	i = 0;
	while (input.dirname[i])
	{
		if (flag == 1)
			ft_printf_s("%:\n", 0, input.dirname[i]);
		do_ls(input.dirname[i], input);
		if (flag == 1)
			;
		else if (flag == 1 && input.option[key('R')] != 1)
			ft_putstr("\n");
		if (i < input.dirnum - 1)
			ft_putstr("\n");
		i++;
	}
}
