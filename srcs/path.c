/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:28:34 by mhori             #+#    #+#             */
/*   Updated: 2020/12/04 04:00:23 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

char	*path_to_filename(char *s)
{
	char	*ret;
	int		len;
	int		i;

	if (s == NULL)
	{
		ft_putstr("somthing wrong with path_to_filename\n");
		return (NULL);
	}
	len = ft_strlen(s);
	i = len - 1;
	while (i >= 0)
	{
		if (s[i] == '/')
		{
			ret = ft_strdup(s + i + 1);
			return (ret);
		}
		i--;
	}
	ret = ft_strdup(s);
	return (ret);
}

char	*filename_to_path(char *dirname, char *inner_dirname)
{
	char *path;

	if (dirname[0] == '.' && dirname[1] != '/')
	{
		path = ft_strdup(inner_dirname);
		return (path);
	}
	path = ft_strjoin3(dirname, inner_dirname);
	return (path);
}

void	convert_path(char *dirname, char **inner_dirname, char ***path)
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
		return ;
	}
	i = 0;
	while (inner_dirname[i])
	{
		(*path)[i] = ft_strjoin3(dirname, inner_dirname[i]);
		i++;
	}
	(*path)[i] = NULL;
}

void	path_to_filename_2d(char ***s)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*s)[i])
	{
		tmp = (*s)[i];
		(*s)[i] = path_to_filename((*s)[i]);
		free(tmp);
		i++;
	}
}
