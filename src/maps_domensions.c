/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_domensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:04:05 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/03 13:37:58 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	calculate_dimensions_screen_maps(t_map *map)
{
	int	max_width;
	int	max_height;

	mlx_get_monitor_size(0, &max_width, &max_height);
	if (max_width == 0 || max_height == 0)
	{
		max_width = 1920;
		max_height = 1080;
	}
	return (1);
}

int	calulete_dimensions_maps(t_map	*map, int max_swidth, int max_sheight)
{
		///em andamento
}