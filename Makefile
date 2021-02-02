# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 16:43:28 by sbudding          #+#    #+#              #
#    Updated: 2021/02/02 10:55:12 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

FLAGS = -Wall -Wextra -Werror

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
	src/utils.c

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

%.o:%.c cub3d.h
	@gcc $(FLAGS) -I mlx -c $< -o $@

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
		$(MAKE) clean -C ./libft/gnl
		rm -rf $(NAME) libft.a gnl.a

re: fclean all


