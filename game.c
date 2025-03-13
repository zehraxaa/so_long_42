/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:53:10 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 08:37:47 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int step_x, int step_y)
{
	char	next;
	char	current;

	current = game->map->vector[(game->player).y][(game->player).x];
	next = game->map->vector[(game->player).y + step_y][(game->player).x
		+ step_x];
	if (next != WALL && next != EXIT)
	{
		(game->move_count)++;
		ft_printf("movement: %d\n", game->move_count);
		if (next == COLLECTIBLE)
			game->collectible_count--;
		if (current != EXIT)
		{
			game->map->vector[(game->player).y][(game->player).x] = FLOOR;
			game->map->vector[(game->exit).y][(game->exit).x] = EXIT;
		}
			game->map->vector[(game->player).y + step_y][(game->player).x
				+ step_x] = PLAYER;
		game->player.x = game->player.x + step_x;
		game->player.y = game->player.y + step_y;
	}
		if ((next == EXIT) && (game->collectible_count == 0))
			close_game_for_move(game);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W || keycode == UP)
		move_player(game, 0, -1);
	else if (keycode == S || keycode == DOWN)
		move_player(game, 0, 1);
	else if (keycode == A || keycode == LEFT)
		move_player(game, -1, 0);
	else if (keycode == D || keycode == RIGHT)
		move_player(game, 1, 0);
	else
		return (0);
	render_map(game);
	return (0);
}

int	expose_handler(t_game *game)
{
	render_map(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, 2, 1, key_handler, game);
	mlx_hook(game->mlx_window, CROSS, 17, close_game, game);
	mlx_expose_hook(game->mlx_window, expose_handler, game);
}

void	close_game_for_move(t_game *game)
{
	ft_printf("***YOU WON THE GAME. TOTAL STEPS: %d***\n", game->move_count);
	close_game(game);
}
