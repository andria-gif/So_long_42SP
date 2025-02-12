/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_flood_free_copy                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:44:02 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 19:14:33 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_copy_maps(char **copy, int height)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (i < height)
	{
		i++;
		if (copy[i])
			free(copy[i]);
	}
	free(copy);
}

int	free_maps(char **grid, int heigth)
{
	int	i;

	i = 0;
	if (!grid)
		return (0);
	while (i < heigth && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (1);
}

int	flood_fill_maps(t_game *game, char **maps, int x, int y)
{
	if (x < 0 || y < 0 || !maps[y] || x >= (int)ft_strlen(maps[y])
		|| maps[y][x] == '1' || maps[y][x] == 'V')
		return (0);
	if (maps[y][x] == 'C')
	{
		game->collectibles_count--;
		maps[y][x] = 'V';
	}
	if (maps[y][x] == '0')
		maps[y][x] = 'V';
	flood_fill_maps(game, maps, x + 1, y);
	flood_fill_maps(game, maps, x - 1, y);
	flood_fill_maps(game, maps, x, y + 1);
	flood_fill_maps(game, maps, x, y - 1);
	return (1);
}
