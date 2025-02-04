/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:39:13 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/04 20:31:50 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Bad request", 2);
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

// void	free_game(t_game *game)
// {
// 	t_map	*map;

	
// 		mlx_destroy_image(game->mlx, game->);
// }