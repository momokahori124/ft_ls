#ifndef COLOR_H
# define COLOR_H

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define MAGENT	"\033[35m"
# define CYAAN	"\033[36m"
# define WHITE	"\033[37m"
# define B_RESET "\033[49m"
# define B_YELLOW "\033[43m"
# define B_CYAAN "\033[46m"

void	putstr_red(char *s);
void	putstr_blue(char *s);
void	putstr_magent(char *s);
void	putstr_blue_back_yellow(char *s);
void	putstr_blue_back_cyaan(char *s);

#endif
