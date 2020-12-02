
#include "../head.h"

void	putstr_red(char *s)
{
	write(1, RED, 5);
	write(1, s, ft_strlen(s));
	write(1, RESET, 4);
	write(1, "\n", 1);
}

void	putstr_blue(char *s)
{
	write(1, BLUE, 5);
	write(1, s, ft_strlen(s));
	write(1, RESET, 4);
	write(1, "\n", 1);
}

void	putstr_magent(char *s)
{
	write(1, MAGENT, 5);
	write(1, s, ft_strlen(s));
	write(1, RESET, 4);
	write(1, "\n", 1);
}

void	putstr_blue_back_yellow(char *s)
{
	write(1, B_YELLOW, 5);
	write(1, BLUE, 5);
	write(1, s, ft_strlen(s));
	write(1, B_RESET, 5);
	write(1, RESET, 4);
	write(1, "\n", 1);
}

void	putstr_blue_back_cyaan(char *s)
{
	write(1, B_CYAAN, 5);
	write(1, BLUE, 5);
	write(1, s, ft_strlen(s));
	write(1, B_RESET, 5);
	write(1, RESET, 4);
	write(1, "\n", 1);
}
