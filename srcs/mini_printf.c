#include "../head.h"

ll	 ft_nbrlen(int width, ll n)
{
	ll count;

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

void	d_sub(int width, ll n)
{
	ll len;
	int box;
	int i;
	
	len = ft_nbrlen(width, ft_abs(n));
	box = width - len;
	if (n < 0)
		box--;
	i = 0;
	while (i < box)
	{
		ft_putchar_fd(' ', 0);
		i++;
	}
	if (n < 0)
		ft_putchar_fd('-', 0);
	ft_putnbr_fd(ft_abs(n), 0);	
}

void	ft_printf_d(char *fmt, int width, ll n)
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
			ft_putchar_fd(*fmt, 0);
			fmt++;
		}
	}
}

void	s_sub(int width, char *t)
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
		ft_putchar_fd(' ', 0);
		i++;
	}
	ft_putstr(t);
}

void	ft_printf_s(char *fmt, int width, char *t)
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
			ft_putchar_fd(*fmt, 0);
			fmt++;
		}
	}
}
