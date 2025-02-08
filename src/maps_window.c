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

static int	get_map_widith(t_game *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
		i++;
	return (i);
}

static int	get_map_height(t_game *map)
{
	int		i;

	i = 0;
	if (map->map != NULL && map->map[i] != NULL)
	{
		while (map->map[0][i])
		{
			i++;
		}
	}
	return (i);
}

int	window(t_game *game)
{
	void	*win_ptr;
	int		win_width;
	int		win_height;

	win_height = get_map_height(game);
	win_width = get_map_widith(game);
	win_ptr = mlx_new_window(game->mlx_ptr, win_width * TILE_SIZE,
			win_height * TILE_SIZE, "window");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
	return (0);
}
