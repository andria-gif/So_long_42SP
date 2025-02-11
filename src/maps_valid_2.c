/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:50:25 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/11 18:38:17 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ber(char *map_path)
{
	int	len ;

	len = ft_strlen(map_path);
	if (len < 4 || ft_strcmp(map_path + len - 4, ".ber") != 0)
	{
		ft_putstr_fd("Error: Invalid file extension. Must be .ber\n", 2);
		return (0);
	}
	return (1);
}

void	block_two_player(t_game *game)
{
	int		i;
	int		j;
	int		count_player;

	count_player = 0;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				count_player++;
			j++;
		}
		i++;
	}
	if (condition_player(count_player))
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		exit(1);
	}
}
