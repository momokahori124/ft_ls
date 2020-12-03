/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:59:20 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 03:58:44 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int		key(char c)
{
	if (c == 'l')
		return (0);
	else if (c == 'a')
		return (1);
	else if (c == 'R')
		return (2);
	else if (c == 'u')
		return (3);
	else if (c == 'U')
		return (4);
	else if (c == 's')
		return (5);
	else if (c == 'S')
		return (6);
	else if (c == 'G')
		return (7);
	return (8);
}

char	*ft_strjoin3(char *s, char *t)
{
	int		len;
	char	*ret;
	int		i;
	int		j;

	len = ft_strlen(s) + ft_strlen(t) + 10;
	ret = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '/';
	i++;
	j = 0;
	while (t[j])
	{
		ret[i + j] = t[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

void	is_u_first(char *save, t_input *input)
{
	int		count;

	while (save[count])
		count++;
	count--;
	while (count >= 0)
	{
		if (save[count] == 'u')
		{
			input->is_u_first = 1;
			break ;
		}
		else if (save[count] == 'U')
			break ;
		count--;
	}
}

void	get_max_total(t_input *input, struct stat buf)
{
	input->max_blocks = ft_max(buf.st_blocks, input->max_blocks);
	input->total += buf.st_blocks;
	input->count++;
}
