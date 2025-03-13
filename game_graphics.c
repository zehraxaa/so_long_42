/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:36:17 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 08:28:26 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx, game->img_ptr.player);
	mlx_destroy_image(game->mlx, game->img_ptr.wall);
	mlx_destroy_image(game->mlx, game->img_ptr.floor);
	mlx_destroy_image(game->mlx, game->img_ptr.collectible);
	mlx_destroy_image(game->mlx, game->img_ptr.exit);
	mlx_destroy_window(game->mlx, game->mlx_window);
	free_map(game->map->vector);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!(game->mlx))
		print_error("Error\nmlx cannot initialized\n", game);
	game->mlx_window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "so_long");
	if (!(game->mlx_window))
		print_error("Error\nmlx window cannot initialized\n", game);
	(game->img_ptr).floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	(game->img_ptr).wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	(game->img_ptr).player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	(game->img_ptr).collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	(game->img_ptr).exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	if (!(game->img_ptr).floor || !(game->img_ptr).wall
		|| !(game->img_ptr).player || !(game->img_ptr).collectible
		|| !(game->img_ptr).exit)
		print_error("Error\ntexture loading failed\n", game);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->vector[i])
	{
		j = 0;
		while (game->map->vector[i][j])
		{
			put_image(game, j, i);
			j++;
		}
		i++;
	}
}

void	put_image(t_game *game, int j, int i)
{
	if (game->map->vector[i][j] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).floor, j * 64, i * 64);
	else if (game->map->vector[i][j] == WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).wall, j * 64, i * 64);
	else if (game->map->vector[i][j] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).player, j * 64, i * 64);
	else if (game->map->vector[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).collectible, j * 64, i * 64);
	else if (game->map->vector[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			(game->img_ptr).exit, j * 64, i * 64);
}
