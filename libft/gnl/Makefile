# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 12:00:37 by sbudding          #+#    #+#              #
#    Updated: 2021/02/05 15:41:30 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
SRC = 	get_next_line.c \
		ft_strdup.c \
		ft_strjoin.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
		ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re