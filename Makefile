# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 10:05:37 by mpytienk          #+#    #+#              #
#    Updated: 2018/03/06 15:08:56 by mpytienk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		mda_handler.c \
		input_parser.c \
		env_handler.c \
		exacute.c \
		new_split.c \
		sig_handler.c \
		bi_setenv.c \
		bi_unsetenv.c \
		bi_cd.c \
		bi_echo.c \
		misc.c \
		misc2.c \
		bi_env.c \
		bi_env2.c \
		bi_exit.c \
				
SRC_DIR =	./src/
OBJ_DIR =	./obj/
INCLUDES =	includes/minishell.h
NAME =		minishell
CFLAGS =	-Wall -Wextra -Werror
LIBDIR =	./libft
CC =		gcc
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBDIR)/libft.a
	@echo "\033[0;32m>>>$(NAME) compiled<<<\033[0m"

$(OBJ_DIR)%.o: %.c $(INCLUDES)
	@echo "\033[0;32mCreating\033[0m \033[31m>>>$@<<<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBDIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make clean -C $(LIBDIR)
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ)
	@echo "\033[31m$(NAME) cleand!\033[0m";

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) fcleand!\033[0m";

re: fclean all

vpath %.c $(SRC_DIR)
