/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:41:51 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 08:28:44 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(int i, int j, char **map_vector, t_map *map)
{
	if (i < 0 || i > map->height || j < 0 || j > map->width)
		return ;
	while (map_vector[i][j] != '1' && map_vector[i][j] != 'F')
	{
		map_vector[i][j] = 'F';
		flood_fill(i + 1, j, map_vector, map);
		flood_fill(i - 1, j, map_vector, map);
		flood_fill(i, j + 1, map_vector, map);
		flood_fill(i, j - 1, map_vector, map);
	}
}

static char	**create_copied_map_vector(t_map *map)
{
	char	**vector;
	int		i;

	vector = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!vector)
	{
		ft_putstr_fd("Error\nallocation error while copying vector\n", 2);
		exit(EXIT_FAILURE);
	}
	vector[map->height] = NULL;
	i = 0;
	while (map->vector[i])
	{
		vector[i] = ft_strdup(map->vector[i]);
		i++;
	}
	return (vector);
}

int	is_path_valid(t_game *game)
{
	int		i;
	int		j;
	char	**copied_vector;

	copied_vector = create_copied_map_vector(game->map);
	flood_fill((game->player).y, (game->player).x, copied_vector, game->map);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game ->map->width)
		{
			if ((copied_vector[i][j] == EXIT)
				|| (copied_vector[i][j] == COLLECTIBLE))
			{
				free_map(copied_vector);
				return (1);
			}
			j++;
		}
		i++;
	}
	free_map(copied_vector);
	return (0);
}
