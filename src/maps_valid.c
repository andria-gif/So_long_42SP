/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:22:09 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/22 20:06:13 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	retang_check_maps(t_map *map)
{
	int	i;

	i = 1;
	while (i < map -> height)
	{
		if ((int) ft_strlen (map -> grid[i] != map -> width))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	border_check_maps(t_map *map)
{
	int	i;

	i = 0;
	if (!retang_check_maps(map))
		return (0);
	while (i < map -> height)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map -> width)
	{
		if (map->grid[0][i] != '1' || map->grid[map-> width - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	corridors_check_maps(t_map *map)
{

}

int	ofc_check_maps(t_map *map)
{
	if (!retang_check_maps(map))
	{
		return (ft_putstr_fd("[ERROR] MAPS NOT RETANGLE\n", 2), NULL);
	}
	if (!borders_check_maps(map))
	{
		return (ft_putstr_fd("[ERROR] INVALID BORDER MAPS\n", 2), NULL);
	}
	if (!corridors_check_maps(map))
	{
		return (ft_putstr_fd("[ERROR] INVALID CORRIDORS MAPS\n", 2), NULL);
	}
	return (map);
}
