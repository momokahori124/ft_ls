#include "../head.h"

void	put_filetype(int n)
{
	if ((S_IFMT & n) == S_IFREG)
        ft_putstr("-");
    else if ((S_IFMT & n) == S_IFDIR)
        ft_putstr("d");
    else
    {
        // 変更するべき
        ft_putstr("?");
    }
}

void	init_per(char *s)
{
	s[0] = 'r';
	s[1] = 'w';
	s[2] = 'x';	
}

int		ft_pow(int n, int p)
{
	int i = 0;
	int ret;

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
	char s[3];
	int j;

	init_per(s);
	j = 0;
	while (j < 3)
	{
	    if (!(n & 1))//1がたってない時
	        s[3 - j - 1] = '-';
	    n = n >> 1;
	    j++;
	}
	printf("%c%c%c", s[0], s[1], s[2]);
}

/*
8進数でパーミッションが与えられるので、
上の桁から順番にbitシフトで計算する

644の時
6 -> 110 -> rw-
4 -> 100 -> r--
4 -> 100 -> r--
*/

void    put_permission(int per)
{
    int n;
	int d;
	int i;

	put_filetype(n);
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
