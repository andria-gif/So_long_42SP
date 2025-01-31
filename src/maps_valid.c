/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:22:09 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/29 16:12:59 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	retang_check_maps(t_map *map)
{
	int	i;

	i = 1;
	while (i < map -> height)
	{
		if ((int) ft_strlen(map->grid[i]) != map->width)
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
	while (i < map -> width)
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
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	components_check_maps(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] != 'P' && map->grid[i][j] != 'E'
				&& map->grid[i][j] != 'C' && map->grid[i][j]!= '1'
					&& map->grid[i][j] != 'O')
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ofc_check_maps(t_map *map)
{
	if (!retang_check_maps(map))
	{
		return (ft_putstr_fd("[ERROR] MAPS NOT RETANGLE\n", 2), 0);
	}
	if (!border_check_maps(map))
	{
		return (ft_putstr_fd("[ERROR] INVALID BORDER MAPS\n", 2), 0);
	}
	if (!components_check_maps(map))
	{
		return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
	}
	return (1);
}
