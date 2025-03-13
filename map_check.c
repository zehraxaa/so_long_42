/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:50:13 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 08:28:37 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (file_name[i - 1] == 'r' && file_name[i - 2] == 'e'
		&& file_name[i - 3] == 'b' && file_name[i - 4] == '.')
		return (0);
	else
		return (1);
}

int	wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->width)
	{
		if ((game->map->vector[0][i] == WALL)
			&& (game->map->vector[game->map->height - 1][i] == WALL))
			i++;
		else
			return (1);
	}
	i = 1;
	while (i < game->map->height - 1)
	{
		if (game->map->vector[i][0] == WALL
			&& game->map->vector[i][game->map->width - 1] == WALL)
			i++;
		else
			return (1);
	}
	return (0);
}

int	component_count(t_game *game, int i, int j, t_count *count)
{
	char	*arr;

	arr = game->map->vector[i];
	while (j < game->map->width)
	{
		if ((arr[j] != WALL) && (arr[j] != FLOOR) && (arr[j] != PLAYER)
			&& (arr[j] != COLLECTIBLE) && (arr[j] != EXIT))
			return (1);
		if (arr[j] == PLAYER)
		{
			(count->player)++;
			(game->player).x = j;
			(game->player).y = i;
		}
		else if (arr[j] == COLLECTIBLE)
			(count->collectible)++;
		else if (arr[j] == EXIT)
		{
			(count->exit)++;
			(game->exit).x = j;
			(game->exit).y = i;
		}
		j++;
	}
	return (0);
}

int	component_count_control(t_game *game)
{
	static t_count	count;
	int				i;

	i = 0;
	while (i < game->map->height)
	{
		if (component_count(game, i, 0, &count) == 1)
			return (2);
		i++;
	}
	if ((count.collectible < 1) || (count.exit != 1) || (count.player != 1))
		return (1);
	game->collectible_count = count.collectible;
	return (0);
}

void	rect_ctl(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->vector[i] && game->map->vector[i + 1])
	{
		if (ft_strlen(game->map->vector[i])
			!= ft_strlen(game->map->vector[i + 1]))
		{
			print_error("Error\nmap is not rectangular\n", game);
		}
		i++;
		game->map->width = ft_strlen(game->map->vector[i]);
	}
}
