/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:58:54 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 20:12:04 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	fsave_2d(char ***tmp, char **s)
{
	int i;

	while (s[i])
		i++;
	*tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (s[i])
	{
		(*tmp)[i] = ft_strdup(s[i]);
		i++;
	}
	(*tmp)[i] = NULL;
}

void	free_2d(char ***s)
{
	int i;

	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i++;
	}
	free((*s));
	(*s) = NULL;
}

int		is_option(char c)
{
	if (c == 'G' || c == 'R' || c == 's' || c == 'S')
		return (1);
	if (c == 'u' || c == 'U')
		return (1);
	return (0);
}

int		is_option_valid(char *av[])
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-')
			return (0);
		if (av[i][1] == '\0')
			return (0);
		j = 1;
		while (av[i][j])
		{
			if (!is_option(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
