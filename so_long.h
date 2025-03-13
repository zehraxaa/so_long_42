/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:50:36 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/13 08:14:13 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define ESC 65307
# define A 97
# define S 115
# define D 100
# define W 119
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362

# define CROSS 17
# define KEY_PRESS 02

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_map
{
	char		**vector;
	char		*name;
	int			width;
	int			height;
}				t_map;

typedef struct s_img
{
	void		*floor;
	void		*wall;
	void		*collectible;
	void		*player;
	void		*exit;
}				t_img;

typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*mlx_window;
	int			collectible_count;
	int			move_count;
	t_img		img_ptr;
	t_player	player;
	t_exit		exit;
}				t_game;

typedef struct s_count
{
	int			exit;
	int			player;
	int			collectible;
}				t_count;

int		wall_check(t_game *game);
int		component_count(t_game *game, int i, int j, t_count *count);
int		component_count_control(t_game *game);
void	rect_ctl(t_game *game);

int		is_path_valid(t_game *game);

void	map_height(t_map *map);
void	create_map(t_game *game);

void	errors(t_game *game);
int		ber_check(char *file_name);
void	free_map(char **map);
void	print_error(char *message, t_game *game);
void	print_error2(char *message, int fd);

int		close_game(t_game *game);
void	move_player(t_game *game, int step_x, int step_y);
void	close_game_for_move(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);
void	put_image(t_game *game, int j, int i);
int		expose_handler(t_game *game);
void	setup_hooks(t_game *game);
int		key_handler(int keycode, t_game *game);

#endif