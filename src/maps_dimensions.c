/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_domensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:04:05 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 18:41:01 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_widith(char **map_map)
{
	char	*map;

	map = *map_map;
	if (!map[0])
		return (0);
	return (ft_strlen(map[0] - 1));
}
//ababora

int	get_map_height(char **map_map)
{
	int		i;

	i = 0;
	while (map_map[i])
		i++;
	return (i);
}

int unity_dimenssions_map(char **map, int max_width, int max_height)
{
	int		width;
	int		height;

	width = get_map_widith(map);
	height = get_map_height(map);
	if (width * TILE_SIZE > max_width || height * TILE_SIZE > max_height)
	{
		ft_putstr_fd("[ERROR] Map too large for screen\n", 2);
		free_copy_maps(map, height);
		return (0);
	}
	return (1);
}

// int	calculate_dimensions_screen_maps(t_map *map)
// {
// 	(void)map;
// 	int	max_width;
// 	int	max_height;

// 	mlx_get_monitor_size(0, &max_width, &max_height);
// 	if (max_width == 0 || max_height == 0)
// 	{
// 		max_width = 1920;
// 		max_height = 1080;
// 	}
// 	return (1);
// }

// int	calulete_dimensions_maps(t_map	*map, int max_swidth, int max_sheight)
// {
// 	int	max_width;
// 	int	heigth;
// 	int	current_width;

// 	max_width = 0;
// 	heigth = 0;
// 	while (map->grid[heigth])
// 	{
// 		current_width = ft_strlen(map->grid[heigth]);
// 		if (current_width > max_width)
// 			max_width = current_width;
// 		heigth++;
// 	}
// 	map->height = heigth;
// 	map->width = max_width;
// 	while (max_width * TILE_SIZE > max_swidth
// 		|| heigth * TILE_SIZE > max_sheight)
// 	{
// 		ft_putstr_fd("[ERROR] Map too large for screen\n", 2);
// 		free_copy_maps(map->grid, map->height);
// 		map->grid = NULL;
// 		return (0);
// 	}
// 	return (1);
// }