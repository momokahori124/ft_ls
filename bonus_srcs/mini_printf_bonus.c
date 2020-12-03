/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:59:02 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 04:48:41 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

long long		ft_nbrlen(long long n)
{
	long long count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void			d_sub(int width, long long n)
{
	long long	len;
	int			box;
	int			i;

	len = ft_nbrlen(ft_abs(n));
	box = width - len;
	if (n < 0)
		box--;
	i = 0;
	while (i < box)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (n < 0)
		ft_putchar_fd('-', 1);
	ft_putnbr_fd(ft_abs(n), 1);
}

void			ft_printf_d(char *fmt, int width, long long n)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			d_sub(width, n);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			fmt++;
		}
	}
}

void			s_sub(int width, char *t)
{
	int len;
	int box;
	int i;

	len = 0;
	while (t[len])
		len++;
	box = width - len;
	i = 0;
	while (i < box)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr(t);
}

void			ft_printf_s(char *fmt, int width, char *t)
{
	if (ft_min(width, ft_strlen(t)) < 0)
		width = ft_strlen(t);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			s_sub(width, t);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			fmt++;
		}
	}
}
