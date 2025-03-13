/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:32:01 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 09:28:55 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height(t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map->name, O_RDONLY);
	if (fd < 0)
		print_error2("Error\nopen\n", 2);
	i = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	map->height = i;
}

static size_t	line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

static void	create_map_vector(t_game *game, int fd, int height)
{
	int		i;
	char	*line_map;
	char	**line_vector;

	line_vector = (char **)malloc(sizeof(char *) * (height + 1));
	if (!line_vector)
		print_error2("Error\nmalloc\n", 2);
	line_vector[height] = NULL;
	i = 0;
	while (i < height)
	{
		line_map = get_next_line(fd, 0);
		if (!line_map)
			print_error2("Error\nget_next_line\n", 2);
		line_vector[i] = ft_substr(line_map, 0, line_len(line_map));
		if ((i == height - 1) && (line_map[ft_strlen(line_map) - 1] == '\n'))
		{
			if(line_map)
				free(line_map);
			get_next_line(fd, 1);
			free_map(line_vector);
			print_error("Error\nincorrect character at the end\n", game);
		}
		free(line_map);
		i++;
	}
	game->map->vector = line_vector;
}

void	create_map(t_game *game)
{
	int	fd;

	fd = open(game->map->name, O_RDONLY);
	if (fd < 0)
		print_error2("Error\nfile could not opened\n", 2);
	map_height(game->map);
	create_map_vector(game, fd, game->map->height);
	close(fd);
}
