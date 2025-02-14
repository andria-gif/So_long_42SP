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
	game->map = read_map(map_path);
	game->map_cpy = read_map(map_path);
	if (!game->map || !game->map_cpy)
	{
		ft_putstr_fd("Error\nMap not loaded\n", 2);
		exit(1);
	}
	dimenssions_map(game);
	game->player_in_x = player_position_x(game->map);
	game->player_in_y = player_position_y(game->map);
	game->collectibles = count_chars_game(game->map, 'C');
	if (!ofc_check_maps(game))
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmlx not initialized\n", 2);
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "window");
	load_textures(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		return (1);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 33);
		return (1);
	}
	initializer_game(game, argv[1]);
	init_img(game);
	render_map_2(game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, 17, 1L << 17, exit_game, game);
	mlx_loop(game->mlx);
	free_maps(game->map, game->map_height);
	exit_game(game);
	free(game);
	return (0);
}
