CC = cc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = ft_printf.h
SRC = src/main.c src/inits_allocs.c src/init_utils.c src/init_utils2.c\
src/init_utils3.c src/parser.c src/parser_utils.c src/finish.c\
src/get_next_line.c\
src/get_next_line_utils.c src/texture.c\
src/setter1.c src/setter2.c src/key.c src/animation.c src/draw_mini.c\
src/draw.c src/destroy.c src/move.c src/mouse.c

OBJ = $(SRC:.c=.o)
NAME = cub3D
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
