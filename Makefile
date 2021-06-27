NAME = microBash

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

$(NAME): $(OBJ) $(LIBFT) $(GNL) microBash.h
	gcc libft.a gnl.a $(OBJ) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft
	cp libft/libft.a .

$(GNL):
	$(MAKE) -C ./libft/gnl
	cp libft/gnl/gnl.a .

%.o:%.c microBash.h
	@gcc $(FLAG) -c $< -o $@

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./libft/gnl
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(MAKE) fclean -C ./libft/gnl
		rm -rf $(NAME) libft.a gnl.a

re: fclean all


