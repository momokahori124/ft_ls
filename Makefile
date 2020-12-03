# Colors
_GREY		=	\x1b[30m
_RED		=	\x1b[31m
_GREEN		=	\x1b[32m
_YELLOW		=	\x1b[33m
_BLUE		=	\x1b[34m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_WHITE		=	\x1b[37m
_END		= 	\x1b[0m

SRCFILE = main.c \
		option.c \
		utils.c \
		sort.c \
		display.c \
		each_do_ls.c \
		permission.c \
		cmp.c \
		check_filetype.c \
		path.c \
		mini_printf.c \
		free.c \
		color_print_bonus.c \
		input.c

BNSFILE = main_bonus.c \
		option_bonus.c \
		utils_bonus.c \
		sort_bonus.c \
		display_bonus.c \
		each_do_ls_bonus.c \
		permission_bonus.c \
		cmp_bonus.c \
		check_filetype_bonus.c \
		path_bonus.c \
		mini_printf_bonus.c \
		free_bonus.c \
		color_print_bonus.c \
		input_bonus.c

SRCDIR = srcs/
BNSDIR =bonus_srcs/

SRCS = $(addprefix $(SRCDIR), $(SRCFILE))
BSRCS = $(addprefix $(BNSDIR), $(BNSFILE))

INCS = includes/head.h

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = ft_mini_ls

CC = gcc

LIBS = Libft
LIBFT = Libft/libft.a

%.o: %.c
	@$(CC) -c -o $@ $<

$(NAME): $(OBJS)
	@echo "$(_GREEN) Making... $(_END)"
	@make -C $(LIBS)
	@echo "$(_GREEN) Finish making Libft.a. $(_END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(INCS)
	@echo "$(_GREEN) Executable '$(NAME)' created. $(_END)❤️"
	@echo "$(_GREEN) Try ./$(NAME) to use. $(_END)"

all :$(NAME)

bonus :$(BOBJS)
	@echo "$(_GREEN) Making bonus... $(_END)"
	@make -C $(LIBS)
	@echo "$(_GREEN) Finish making Libft.a. $(_END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBFT) -I $(INCS)
	@echo "$(_GREEN) Executable '$(NAME)' created. $(_END)❤️"
	@echo "$(_GREEN) Try ./$(NAME) to use. $(_END)"

clean:
	@make clean -C $(LIBS)
	@rm -f $(OBJS) $(BOBJS)
	@echo " $(_RED)Object files has been deleted. $(_END)"

fclean: clean
	@make fclean -C $(LIBS)
	@rm -f $(NAME)
	@echo " $(_RED)$(LIBFT) has been deleted.$(_END)"
	@echo " $(_RED)Executable file has been deleted. $(_END)"

re: fclean all

.PHONY: all clean fclean re
