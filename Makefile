# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 16:43:28 by sbudding          #+#    #+#              #
#    Updated: 2021/02/15 16:07:48 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

FLAG = -Wall -Wextra -Werror

LIBFT = libft.a

GNL = gnl.a

SRC = main.c \
	cmd/echo.c \
	cmd/pwd.c \
	cmd/cd.c \
	cmd/env.c \
	cmd/export.c \
	cmd/unset.c \
	cmd/exit.c \
	src/loop.c \
	src/env_set.c \
	src/executable.c \
	src/redir.c \
	src/signal.c \
	src/utils.c \
	src/errors.c \
	pars/echo_arg.c \
	pars/list_functions.c \
	pars/list_refactoring.c \
	pars/mult_arg.c \
	pars/mult_arg_extra.c \
	pars/new_string.c \
	pars/parser_extra.c \
	pars/parser.c \
	pars/processing_extra.c \
	pars/symbols_processing.c \
	pars/syntax_errors.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) minishell.h
	gcc libft.a gnl.a $(OBJ) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft
	cp libft/libft.a .

$(GNL):
	$(MAKE) -C ./libft/gnl
	cp libft/gnl/gnl.a .

%.o:%.c minishell.h
	@gcc $(FLAG) -c $< -o $@

run: $(NAME)
	./$(NAME)

git:
	git add .
	git commit -m save

norm:
	@norminette $(SRC) minishell.h libft/*.c libft/*.h libft/gnl/*.c libft/gnl/*.h 

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./libft/gnl
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(MAKE) fclean -C ./libft/gnl
		rm -rf $(NAME) libft.a gnl.a

re: fclean all


