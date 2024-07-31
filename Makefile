CC = cc
CFLAGS = #-Wall -Wextra -Werror -g
HEAD = ft_printf.h
SRC = src/main.c src/inits_allocs.c src/init_utils.c src/parser.c src/finish.c\
includes_functions/get_next_line/get_next_line.c\
includes_functions/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
NAME = cub_3D
FT_PRINTF = ./includes_functions/ft_printf/libftprintf.a
LIBFT = ./includes_functions/libft/libft.a
MLX_PATH = ./minilibx-linux

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C includes_functions/ft_printf --no-print-directory
	@$(MAKE) -C includes_functions/libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -L$(MLX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -o $(NAME)
.PHONY: all clean fclean re included_functions

clean:
	$(MAKE) -C includes_functions/libft clean
	$(MAKE) -C includes_functions/ft_printf clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C includes_functions/libft fclean
	$(MAKE) -C includes_functions/ft_printf fclean
	rm -f $(NAME)

re: fclean all
