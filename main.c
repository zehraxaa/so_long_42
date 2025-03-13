/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaydogdu <aaydogdu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:28:00 by aaydogdu          #+#    #+#             */
/*   Updated: 2025/03/12 08:28:34 by aaydogdu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_game	game;
	static t_map	map;

	game.map = &map;
	if (ac == 2)
	{
		if (ber_check(av[1]) == 1)
			print_error2("Error\nnot ber file\n", 2);
		(game.map)->name = av[1];
		create_map(&game);
		rect_ctl(&game);
		errors(&game);
		load_textures(&game);
		setup_hooks(&game);
		mlx_loop(game.mlx);
		free_map((game.map)->vector);
	}
	else
		ft_putstr_fd("Error\n2 arguments must be entered!\n", 2);
	return (0);
}
