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

int	get_map_widith(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != NULL)
		i++;
	return (i);
}

int	get_map_height(t_game *game)
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
	game->map_width = get_map_height(game);
	game->map_height = get_map_widith(game);
	game->map_width -= 2;
	return (0);
}