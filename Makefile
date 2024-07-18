CC = cc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = ft_printf.h
SRC = src/main.c

OBJ = $(SRC:.c=.o)
NAME = Cub_3D
FT_PRINTF = ./includes_functions/ft_printf/libftprintf.a
LIBFT = ./includes_functions/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C includes_functions/ft_printf --no-print-directory
	@$(MAKE) -C includes_functions/libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

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
