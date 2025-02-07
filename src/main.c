/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:08:41 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 21:24:44 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	initializer_game(t_game *game, char *map_path)
{
	int	map_heigth;
	int	map_widith;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmlx not initialized\n", 32);
		exit(1);
	}
	game->mlx = read_map(map_path);
	if (!game->map)
	{
		ft_putstr_fd("Error\nMap not loaded\n", 19);
		exit(1);
	}

	
	// map_heigth = get_map_height(game->map);
	// map_widith = get_map_widith(game->map);
	// if (!unity_dimenssions_map(game->map, map_widith, map_heigth))
	// 	exit(1);
	
}

// int	main(int argc, char *argv[])
// {
// 	t_game	*game;

// 	ft_check_argc(argc);
	
// 	render_map_2(game, 0, 0);


// }
