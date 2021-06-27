NAME = gnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
SRC = 	get_next_line.c \
		ft_strdup.c \
		ft_strjoin.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	@gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re