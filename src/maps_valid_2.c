/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_valid_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:50:25 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/11 21:11:44 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	check_ber(char *map_path)
// {
// 	int	len ;

// 	len = ft_strlen(map_path);
// 	if (len < 4 || ft_strncmp(map_path + len - 4, ".ber") != 0)
// 	{
// 		ft_putstr_fd("Error: Invalid file extension. Must be .ber\n", 2);
// 		return (0);
// 	}
// 	return (1);
// }


// int	validate_map(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	count_player;
// 	int	line_length;

// 	count_player = 0;
// 	i = 0;
// 	line_length = ft_strlen(game->map[0]);
// 	while (i < game->map_height)
// 	{
// 		if (ft_strlen(game->map[i]) != line_length)
// 		{
// 			ft_putstr_fd("Error: All lines must have the same length\n", 2);
// 			exit(1);
// 		}
// 		j = 0;
// 		while (j < game->map_width)
// 		{
// 			if (game->map[i][j] == 'P')
// 				count_player++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (condition_player(count_player))
// 	{
// 		ft_putstr_fd("Error: Invalid number of players\n", 2);
// 		exit(1);
// 	}
// 	return (1);
// }

int	check_line_lengths(t_game *game)
{
	int		i;
	size_t	line_length;

	i = 0;
	line_length = ft_strlen(game->map[0]);
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

int	validate_map(t_game *game)
{
	if (!check_line_lengths(game))
		return (0);
	if (!block_two_player(game))
		return (0);
	return (1);
}

int	block_two_player(t_game *game)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (i < game->map_height)
	{
		i++;
		j = 0;
		while (j < game->map_width)
		{
			j++;
			if (game->map[i][j] == 'P')
				count_player++;
		}
	}
	if (count_player != 1)
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		return (0);
	}
	return (1);
}
