NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iget_next_line -Ilibft -Ift_printf -Iminilibx-linux

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

GNL_SRCS = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

SRCS = map_check.c \
       main.c \
       error_messages.c \
       map_path_check.c \
       map_create.c \
	   game_graphics.c \
	   game.c \
       $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@make -C ft_printf
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a ft_printf/libftprintf.a $(MLX_FLAGS)

clean:
	@make -C libft clean
	@make -C ft_printf clean
	@make -C minilibx-linux clean
	@rm -f $(OBJS) $(GNL_OBJS)

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
