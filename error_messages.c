/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:15:12 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 08:31:33 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(t_game *game)
{
	if (component_count_control(game) == 1)
		ft_putstr_fd("Error\nNumber of components is incorrect\n", 2);
	else if (component_count_control(game) == 2)
		ft_putstr_fd("Error\nInvalid component\n", 2);
	else if (wall_check(game) == 1)
		ft_putstr_fd("Error\nWrong type of frame\n", 2);
	else if (is_path_valid(game) == 1)
		ft_putstr_fd("Error\nmap is not valid\n", 2);
	else
		return ;
	free_map(game->map->vector);
	exit (1);
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		exit(1);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_error(char *message, t_game *game)
{
	ft_putstr_fd(message, 2);
	free_map(game->map->vector);
	exit(1);
}

void	print_error2(char *message, int fd)
{
	ft_putstr_fd(message, fd);
	exit (1);
}
