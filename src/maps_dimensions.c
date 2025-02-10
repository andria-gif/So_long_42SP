/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:03:24 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/28 17:19:06 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_map_widith(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != NULL)
		i++;
	return (i);
}

static int	get_map_height(t_game *game)
{
	int	i;

	i = 0;
	if (game->map != NULL && game->map[i] != NULL)
	{
		while (game->map[0][i])
		{
			i++;
		}
	}
	return (i);
}

int	dimenssions_map(t_game *game)
{
	game->width = get_map_height(game);
	game->height = get_map_widith(game);
	game->width -= 2;
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
	return (0);
}
