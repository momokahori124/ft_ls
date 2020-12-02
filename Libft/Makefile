# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momoka <momoka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 10:10:44 by mhori             #+#    #+#              #
#    Updated: 2020/12/03 02:30:49 by momoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
CLIBS	= -L . -lft
RM	= rm -f
AR	= ar rcs
BSRCS	= ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS	=       srcs/ft_atoi.c \
                srcs/ft_bzero.c \
                srcs/ft_calloc.c \
                srcs/ft_isalnum.c\
                srcs/ft_isalpha.c \
                srcs/ft_isascii.c \
                srcs/ft_isdigit.c \
                srcs/ft_isprint.c\
                srcs/ft_itoa.c \
                srcs/ft_memccpy.c \
                srcs/ft_memchr.c \
                srcs/ft_memcmp.c\
                srcs/ft_memcpy.c \
                srcs/ft_memmove.c \
                srcs/ft_memset.c \
                srcs/ft_putchar_fd.c\
                srcs/ft_putendl_fd.c\
                srcs/ft_putnbr_fd.c \
                srcs/ft_putstr_fd.c \
                srcs/ft_split.c \
                srcs/ft_strchr.c\
                srcs/ft_strdup.c \
                srcs/ft_strjoin.c \
                srcs/ft_strlcat.c \
                srcs/ft_strlcpy.c\
                srcs/ft_strlen.c \
                srcs/ft_strmapi.c \
                srcs/ft_strncmp.c \
                srcs/ft_strnstr.c\
                srcs/ft_strrchr.c \
                srcs/ft_strtrim.c \
                srcs/ft_substr.c \
                srcs/ft_tolower.c \
                srcs/ft_toupper.c\
                srcs/ft_min.c \
                srcs/ft_max.c \
                srcs/ft_abs.c 

OBJS	= $(SRCS:%.c=%.o)
BOBJS	= $(BSRCS:%.c=%.o)
LIBNAME	= ../libft.h
NAME	= libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME):$(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS) $(BOBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean	all

$(BOBJS):  $(OBJS)

bonus:$(BOBJS)
	@$(AR) $(NAME) $(OBJS) $(BOBJS)
