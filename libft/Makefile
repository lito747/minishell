# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 10:43:53 by mpytienk          #+#    #+#              #
#    Updated: 2018/02/02 14:20:19 by mpytienk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

MK_LIB = ar rc

NAME = libft.a

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \

OBJ = 	$(SRC:%.c=%.o)

INK = libft.h

CKEY = -c -Wall -Wextra -Werror

all: $(NAME)

.c.o:
		@$(CC) $(CKEY) -I $(INK) $< -o $@

$(NAME): $(OBJ)
		@$(MK_LIB) $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[0;32m>>>$(NAME) compiled<<<\033[0m"

clean:
		@/bin/rm -f $(OBJ)
		@echo "\033[31m$(NAME) cleand!\033[0m";

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[31m$(NAME) fcleand!\033[0m";

re: fclean all
