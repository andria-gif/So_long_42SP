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

void	initializer_game(t_game *game, char *map_path)
{
	int	map_dimensions;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmlx not initialized\n", 32);
		exit(1);
	}
	game->mlx = read_map(map_path);
	map_dimensions = window(game);
	if (!game->map)
	{
		ft_putstr_fd("Error\nMap not loaded\n", 19);
		exit(1);
	}
	init_game(game);
	game->player_in_x = player_position_x(game->map);
	game->collectibles_count = count_chars_game(*game->map, 'C');
	// game->window = mlx_new_window(game->mlx, game->width,
	// 		game->height, "so_long");
	load_textures(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game) *1 );
	if (!game)
		return (1);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 33);
		exit(1);
	}
	initializer_game(game, argv[1]);
	load_textures(game);
	render_map_2(game, 0, 0);
	//mlx_hook(game->window, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}
