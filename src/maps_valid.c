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

static int	border_check_maps(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
		{
			return (0);
		}
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
		while (j < game->map_height)
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C' && game->map[i][j]!= '1'
					&& game->map[i][j] != 'O')
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
			j++;
		}
		i++;
	}
	// if (count_player != 1 || count_exit < 1 || count_collectibles < 1)
    // {
    //     ft_putstr_fd("Error: Map must have exactly one player, at least one exit, and at least one collectible\n", 2);
    //     return (0);
    // }
	return (1);
}

int	ofc_check_maps(t_game *game)
{
	if (!check_line_lengths(game))
		return (ft_putstr_fd("ERROR: ALL LINES MUST HAVE THE SAME LENGTH\n", 2), 0);
	if (!border_check_maps(game))
		return (ft_putstr_fd("[ERROR] INVALID BORDER MAPS\n", 2), 0);
	if (!components_check_maps(game))
		return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
	if (!flood_fill_maps(game, game->map, game->player_in_x, game->player_in_y))
		return (ft_putstr_fd("[ERROR] MAPS NOT VISITED\n", 2), 0);
	return (1);
}
