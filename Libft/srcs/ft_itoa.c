/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momoka <momoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:21:18 by mhori             #+#    #+#             */
/*   Updated: 2020/12/01 00:05:18 by momoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int		word_size(long n)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	void	ft_subitoa(long d, long m, char *ret, int i)
{
	d = 1;
	while (m >= 10 * d)
		d *= 10;
	while (d)
	{
		ret[i] = m / d + '0';
		m %= d;
		i++;
		d /= 10;
	}
	ret[i] = '\0';
}

char			*ft_itoa(int n)
{
	long	m;
	int		i;
	char	*ret;
	long	d;

	d = 1;
	m = (long)n;
	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * word_size(m) + 1)))
		return (NULL);
	if (m < 0)
	{
		ret[i] = '-';
		m *= -1;
		i++;
	}
	ft_subitoa(d, m, ret, i);
	return (ret);
}
