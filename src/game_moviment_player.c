/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moviment_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:51:33 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/11 18:56:05 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_chars_game(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_in_y][game->player_in_x] = '0';
	game->player_in_x = new_x;
	game->player_in_y = new_y;
	if (game->map[new_y][new_x] != 'E')
		game->map[new_y][new_x] = 'P';
	game->moves_count++;
	render_map_2(game);
}

static void	update_game_state(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_in_x + x;
	new_y = game->player_in_y + y;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles_count++;
		game->map[new_y][new_x] = '0';
	}
	else if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles_count == game->collectibles)
		{
			ft_putstr_fd("You win!\n", 1);
			to_clean_game(game);
			exit_game(game);
		}
		return ;
	}
	update_player_position(game, new_x, new_y);
}

void	move_player(t_game *game, int x, int y)
{
	//int	collectibles_remaining;

	if (game->map[game->player_in_y + y][game->player_in_x + x] != '1')
	{
		update_game_state(game, x, y);
	}
	// collectibles_remaining = count_chars_game(game->map, 'C');
	// ft_putstr_fd("Collectibles remaining: ", 1);
	// ft_putnbr_fd(collectibles_remaining, 1);
	// ft_putstr_fd("\n", 1);
	ft_putstr_fd("Steps nubers: ", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putstr_fd("\n", 1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC key
		exit_game(game);
	else if (keycode == 119) // W key
		move_player(game, 0, -1);
	else if (keycode == 115) // S key
		move_player(game, 0, 1);
	else if (keycode == 97) // A key
		move_player(game, -1, 0);
	else if (keycode == 100) // D key
		move_player(game, 1, 0);
	return (0);
}
