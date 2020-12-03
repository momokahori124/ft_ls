/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:59:12 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 04:48:41 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	put_filetype(int n)
{
	if (S_ISREG(n) == 1)
		ft_putstr("-");
	else if (S_ISDIR(n) == 1)
		ft_putstr("d");
	else if (S_ISLNK(n) == 1)
		ft_putstr("l");
	else if (S_ISCHR(n) == 1)
		ft_putstr("b");
	else if (S_ISBLK(n) == 1)
		ft_putstr("c");
	else
		ft_putstr("?");
}

void	init_per(char *s)
{
	s[0] = 'r';
	s[1] = 'w';
	s[2] = 'x';
}

int		ft_pow(int n, int p)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (i < p)
	{
		ret *= n;
		i++;
	}
	return (ret);
}

void	put_rwx(int n)
{
	char	s[3];
	int		j;

	init_per(s);
	j = 0;
	while (j < 3)
	{
		if (!(n & 1))
			s[3 - j - 1] = '-';
		n = n >> 1;
		j++;
	}
	ft_putchar_fd(s[0], 1);
	ft_putchar_fd(s[1], 1);
	ft_putchar_fd(s[2], 1);
}

void	put_permission(int per)
{
	int n;
	int d;
	int i;

	put_filetype(per);
	per = per % ft_pow(8, 3);
	i = 0;
	d = ft_pow(8, 2);
	while (i < 3)
	{
		n = per / d;
		put_rwx(n);
		per = per % d;
		d /= 8;
		i++;
	}
}
