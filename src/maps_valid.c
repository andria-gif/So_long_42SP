/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:22:09 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 21:19:27 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	retang_check_maps(t_game *game)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = 0;
	while (game->map[i])
	{
		line_size = (((int) ft_strlen(game->map[i])) - 2);
		if (i == (game->map_height - 1) && !game->map[i][game->map_width])
			line_size += 2;
		if (line_size != game->map_width)
			return (0);
		i++;
	}
	return (1);
}

static int	border_check_maps(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int	components_check_maps(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E' \
				&& game->map[i][j] != 'C' && game->map[i][j] != '1' \
				&& game->map[i][j] != '0')
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
			else if (game->map[i][j] == 'P')
				game->count_player++;
			else if (game->map[i][j] == 'E')
				game->count_exit++;
			j++;
		}
		i++;
	}
	if (!--game->count_player && !--game->count_exit && game->collectibles)
		return (1);
	return (ft_putstr_fd("ERROR: INVALID COMPONENT", 2), 0);
}

int	ofc_check_maps(t_game *game)
{
	if (!retang_check_maps(game))
		return (0);
	if (!border_check_maps(game))
		return (0);
	if (!components_check_maps(game))
		return (0);
	if (!check_exit(game))
		return (0);
	return (1);
}
