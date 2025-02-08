/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_position_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:32:14 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/08 20:26:02 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_position_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	player_position_y(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	return (-1);
}
