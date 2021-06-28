NAME = microBash

FLAG = -Wall -Wextra -Werror

LIBFT = libft.a

GNL = gnl.a

SRC = src/main.c \
	src/cmd/echo.c \
	src/cmd/pwd.c \
	src/cmd/cd.c \
	src/cmd/env.c \
	src/cmd/export.c \
	src/cmd/unset.c \
	src/cmd/exit.c \
	src/loop.c \
	src/env_set.c \
	src/executable.c \
	src/redir.c \
	src/signal.c \
	src/utils.c \
	src/errors.c \
	src/pars/echo_arg.c \
	src/pars/list_functions.c \
	src/pars/list_refactoring.c \
	src/pars/mult_arg.c \
	src/pars/mult_arg_extra.c \
	src/pars/new_string.c \
	src/pars/parser_extra.c \
	src/pars/parser.c \
	src/pars/processing_extra.c \
	src/pars/symbols_processing.c \
	src/pars/syntax_errors.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) src/microBash.h
	@gcc libft.a gnl.a $(OBJ) -o $(NAME)
	@echo "\033[0;32mSuccess: microBash instaled!\033[0m"

$(LIBFT):
	@$(MAKE) bonus -C ./src/libft
	@cp src/libft/libft.a .

$(GNL):
	@$(MAKE) -C ./src/libft/gnl
	@cp src/libft/gnl/gnl.a .

%.o:%.c src/microBash.h
	@gcc $(FLAG) -c $< -o $@

clean:
		$(MAKE) clean -C ./src/libft
		$(MAKE) clean -C ./src/libft/gnl
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./src/libft
		$(MAKE) fclean -C ./src/libft/gnl
		rm -rf $(NAME) libft.a gnl.a

re: fclean all


