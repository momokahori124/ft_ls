/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:18:38 by mhori             #+#    #+#             */
/*   Updated: 2020/12/04 03:34:16 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int			is_hiddden_file(char *path)
{
	char	*tmp;
	int		ret;

	tmp = path_to_filename(path);
	if (tmp[0] == '.')
		ret = 1;
	else
		ret = 0;
	free(tmp);
	return (ret);
}

void		get_block_max_and_total(char *dir, char **inner, t_input *input)
{
	struct stat		buf;
	char			*path;
	int				i;

	i = 0;
	while (inner[i])
	{
		path = filename_to_path(dir, inner[i]);
		if (lstat(path, &buf) == 0)
		{
			if (is_hiddden_file(path) && input->option[key('a')])
				get_max_total(input, buf);
			else if (!is_hiddden_file(path))
				get_max_total(input, buf);
		}
		free(path);
		i++;
	}
}

void		put_by_option(char *dirname, char *inner, t_input input, int max)
{
	struct stat		buf;
	char			*path;

	path = filename_to_path(dirname, inner);
	if (lstat(path, &buf) == 0)
	{
		if (input.option[key('s')] == 1)
			ft_printf_d("% ", ft_nbrlen(input.max_blocks), buf.st_blocks);
	}
	free(path);
	ft_put_dirname(dirname, inner, input);
}

void		display_2d(char *dirname, char **inner_dirname, t_input input)
{
	int		i;
	int		c;
	char	**path;
	int		max;

	get_block_max_and_total(dirname, inner_dirname, &input);
	if (input.option[key('s')])
	{
		if (input.total == 0 && inner_dirname[0] == NULL)
			;
		else if (input.total == 0 && input.count == 0)
			;
		else
			ft_printf_d("total %\n", 0, input.total);
	}
	i = 0;
	while (inner_dirname[i])
	{
		if (inner_dirname[i][0] != '.' || input.option[key('a')] == 1)
			put_by_option(dirname, inner_dirname[i], input, max);
		i++;
	}
}
