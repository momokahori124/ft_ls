/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momoka <momoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:53:52 by mhori             #+#    #+#             */
/*   Updated: 2020/12/01 00:05:18 by momoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_count(char const *s, char c)
{
	char	*r_ptr;
	char	*l_ptr;
	int		count;

	count = 0;
	r_ptr = (char *)s;
	l_ptr = (char *)s;
	while (*l_ptr)
	{
		while (*r_ptr == c && *r_ptr)
		{
			r_ptr++;
			l_ptr++;
		}
		while (*r_ptr != c && *r_ptr)
			r_ptr++;
		if (l_ptr != r_ptr)
		{
			l_ptr = r_ptr;
			count++;
		}
	}
	return (count);
}

void		ptr_move(char **r_ptr, char **l_ptr, char c)
{
	while (**r_ptr == c)
	{
		(*r_ptr)++;
		(*l_ptr)++;
	}
	while (**r_ptr != c && **r_ptr)
		(*r_ptr)++;
}

int			ft_subsub_split(char const *s, char c, char ***ret)
{
	char	*r_ptr;
	char	*l_ptr;
	int		i;

	r_ptr = (char *)s;
	l_ptr = (char *)s;
	i = 0;
	while (*r_ptr)
	{
		ptr_move(&r_ptr, &l_ptr, c);
		if (l_ptr != r_ptr)
		{
			if (!((*ret)[i] = ft_substr(l_ptr, 0, r_ptr - l_ptr)))
			{
				while (i-- > -1)
					free((*ret)[i]);
				free(*ret);
				return (0);
			}
			l_ptr = r_ptr;
			i++;
		}
	}
	(*ret)[i] = NULL;
	return (1);
}

char		**ft_sub_split(char const *s, char c)
{
	char	**ret;

	if (!(ret = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	if (ft_subsub_split(s, c, &ret) == 0)
		return (NULL);
	return (ret);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	if (!c && !(*s))
	{
		if (!(ret = (char **)malloc(sizeof(char *))))
			return (NULL);
		ret[0] = NULL;
		return (ret);
	}
	ret = ft_sub_split(s, c);
	return (ret);
}
