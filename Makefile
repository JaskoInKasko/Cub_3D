CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_BONUS = -Wall -Wextra -Werror
HEAD = ft_printf.h
SRC = src/main.c src/inits_allocs.c src/init_utils.c src/init_utils2.c\
src/init_utils3.c src/parser.c src/parser_utils.c src/finish.c\
includes_functions/get_next_line/get_next_line.c\
includes_functions/get_next_line/get_next_line_utils.c src/texture.c\
src/setter1.c src/setter2.c src/key.c\
src/draw.c src/destroy.c src/move.c

SRC_BONUS = src_bonus/main.c src_bonus/inits_allocs.c src_bonus/init_utils.c src_bonus/init_utils2.c\
src_bonus/init_utils3.c src_bonus/parser.c src_bonus/parser_utils.c src_bonus/finish.c\
includes_functions/get_next_line/get_next_line.c\
includes_functions/get_next_line/get_next_line_utils.c src_bonus/texture.c\
src_bonus/setter1.c src_bonus/setter2.c src_bonus/key.c src_bonus/animation.c src_bonus/draw_mini.c\
src_bonus/draw.c src_bonus/destroy.c src_bonus/move.c src_bonus/mouse.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = cub3D
NAME_BONUS = cub3D_bonus
FT_PRINTF = ./includes_functions/ft_printf/libftprintf.a
LIBFT = ./includes_functions/libft/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(FT_PRINTF) $(LIBFT)
	@$(CC) $(CFLAGS_BONUS) $(OBJ_BONUS) $(FT_PRINTF) $(LIBFT) -lmlx -lXext -lX11 -lm -o $(NAME_BONUS)

$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -lmlx -lXext -lX11 -lm -o $(NAME)

$(FT_PRINTF):
	@$(MAKE) -C includes_functions/ft_printf --no-print-directory
$(LIBFT):
	@$(MAKE) -C includes_functions/libft --no-print-directory
.PHONY: all clean fclean re included_functions clean_bonus fclean_bonus bonus bonus_re

clean:
	$(MAKE) -C includes_functions/libft clean
	$(MAKE) -C includes_functions/ft_printf clean
	rm -f $(OBJ)

clean_bonus:
	$(MAKE) -C includes_functions/libft clean
	$(MAKE) -C includes_functions/ft_printf clean
	rm -f $(OBJ_BONUS)

fclean: clean
	$(MAKE) -C includes_functions/libft fclean
	$(MAKE) -C includes_functions/ft_printf fclean
	rm -f $(NAME)

fclean_bonus: clean_bonus
	$(MAKE) -C includes_functions/libft fclean
	$(MAKE) -C includes_functions/ft_printf fclean
	rm -f $(NAME_BONUS)

re: fclean all

bonus_re: fclean_bonus bonus
