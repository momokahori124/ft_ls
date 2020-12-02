#include "../head.h"

void	put_filetype(int n)
{
	if (S_ISREG(n) == 1)
        printf("-");
    else if (S_ISDIR(n) == 1)
        printf("d");
	else if (S_ISLNK(n) == 1)
		printf("l");
	else if (S_ISCHR(n) == 1)
		printf("b");
	else if (S_ISBLK(n) == 1)
		printf("c");
	else
		printf("?");
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
	    if (!(n & 1))
	        s[3 - j - 1] = '-';
	    n = n >> 1;
	    j++;
	}
	printf("%c%c%c", s[0], s[1], s[2]);
}

void    put_permission(int per)
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
