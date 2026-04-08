NAME		= so_long
CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g3

SRCS		= main.c events.c graphics.c map_parsing.c map_validation.c
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

# La règle Valgrind (suppose que tu as une carte test.ber dans un dossier maps)
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/test.ber

.PHONY: all clean fclean re valgrind