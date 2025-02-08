/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:39:13 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 21:36:03 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game)
{
	int	i;

	i = -1;
	game->mlx = NULL;
	game->moves_count = 0;
	game->map = NULL;
	while (++i < 5)
		game->imgs[i] = NULL;
}

void	to_clean_game(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->mlx);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(0);
}

void	exit_game(void *game)
{
	t_game	*game_ptr;

	game_ptr = (t_game *)game;
	to_clean_game(game_ptr);
}

// int	error_game(t_map *map, t_game game)
// {
// 	if (!map)
// }
