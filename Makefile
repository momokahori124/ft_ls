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
		srcs/check_filetype.c

INCS = head.h

OBJS = $(SRCS:.c=.o)

NAME = ft_mini_ls

CC = gcc

%.o: %.c
	@$(CC) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -I $(INCS) -g -fsanitize=address
	@echo "$(_GREEN) Executable '$(NAME)' created. $(_END)❤️"
	@echo "$(_GREEN) Try ./$(NAME) to start. $(_END)"

all :$(NAME)

clean: 
	@rm -f $(OBJS)
	@echo " $(_RED)Object files has been deleted. $(_END)"

fclean: clean	
	@rm -f $(NAME)
	@echo " $(_RED)Executable file has been deleted. $(_END)"

re: fclean all

.PHONY: all clean fclean re