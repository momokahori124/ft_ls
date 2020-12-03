/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:59:16 by momoka            #+#    #+#             */
/*   Updated: 2020/12/03 23:49:14 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void		ft_swap(char **s, char **t)
{
	char	*tmp;

	tmp = *s;
	*s = *t;
	*t = tmp;
}

void		sort_by(char **dirname, int (*cmp_func)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (dirname[i])
	{
		j = 0;
		while (dirname[j])
		{
			if ((*cmp_func)(dirname[i], dirname[j]) < 0)
				ft_swap(&(dirname[i]), &(dirname[j]));
			j++;
		}
		i++;
	}
}

void		sort_reverse(char **dirname)
{
	int count;
	int i;

	count = 0;
	while (dirname[count])
		count++;
	i = 0;
	while (i < count / 2)
	{
		ft_swap(&(dirname[i]), &(dirname[count - i - 1]));
		i++;
	}
}

void		copy_path_to_inner(char **inner_dirname, char ***path)
{
	char	*tmp;
	int		i;

	i = 0;
	while (inner_dirname[i])
	{
		tmp = inner_dirname[i];
		inner_dirname[i] = (*path)[i];
		free(tmp);
		i++;
	}
	free(*path);
}

void		sort_dirname(char *dirname, char **inner_dirname, t_input input)
{
	char	**path;
	char	**tmp;
	char	*t;
	int		i;

	convert_path(dirname, inner_dirname, &path);
	copy_path_to_inner(inner_dirname, &path);
	sort_by(inner_dirname, &(cmp_by_mtime));
	if (input.option[key('S')] == 1)
		sort_by(inner_dirname, &(cmp_by_filesize));
	if (input.option[key('u')] == 1)
		sort_by(inner_dirname, &(cmp_by_atime));
	if (input.option[key('U')] == 1)
		sort_by(inner_dirname, &(cmp_by_ctime));
	sort_reverse(inner_dirname);
	path_to_filename_2d(&inner_dirname);
}
