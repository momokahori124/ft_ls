/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:58:54 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 04:48:41 by mhori            ###   ########.fr       */
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
