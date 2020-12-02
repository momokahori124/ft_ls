# Colors
_GREY		=	\x1b[30m
_RED		=	\x1b[31m
_GREEN		=	\x1b[32m
_YELLOW		=	\x1b[33m
_BLUE		=	\x1b[34m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_WHITE		=	\x1b[37m

SRCS = srcs/main.c \
		srcs/option.c \
		srcs/utils.c \
		srcs/sort.c \
		srcs/display.c \
		srcs/each_do_ls.c \
		srcs/debug.c \
		srcs/permission.c \
		srcs/cmp.c \
		srcs/check_filetype.c \
		srcs/path.c \
		srcs/mini_printf.c \
		srcs/free.c \
		srcs/color_print_bonus.c

INCS = head.h

OBJS = $(SRCS:.c=.o)

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

clean: 
	@make clean -C $(LIBS)
	@rm -f $(OBJS)
	@echo " $(_RED)Object files has been deleted. $(_END)"

fclean: clean	
	@make fclean -C $(LIBS)
	@rm -f $(NAME)
	@echo " $(LIBFT) has been deleted."
	@echo " $(_RED)Executable file has been deleted. $(_END)"

re: fclean all

.PHONY: all clean fclean re