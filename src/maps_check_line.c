/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:50:25 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/13 21:06:30 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_line_lengths(t_game *game)
{
	int		i;
	size_t	line_length;

	if (!game->map || !game->map[0])
		return (0);
	line_length = ft_strlen(game->map[0]);
	i = 0;
	while (i < game->map_height)
	{
		i++;
		if (ft_strlen(game->map[i]) != line_length)
		{
			ft_putstr_fd("Error: All lines must have the same length\n", 2);
			return (0);
		}
	}
	return (1);
}
