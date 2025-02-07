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

int	ft_check_argc(int argc, t_game *game)
{
	if (argc != 2)
	{
		ft_putstr_fd("Bad request", 2);
		free(game);
		exit(1);
	}
	return (0);
}

void	init_components_maps(t_map	*map, int *p, int *e)
{
	*p = 0;
	*e = 0;
	map->collectibles_count = 0;
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

// int	error_game(t_map *map, t_game game)
// {
// 	if (!map)
// }
