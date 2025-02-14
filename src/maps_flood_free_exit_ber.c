/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_flood_free_copy                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:44:02 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 19:14:33 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_maps(char **grid, int heigth)
{
	int	i;

	i = 0;
	if (!grid)
		return (0);
	while (i < heigth && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (1);
}

int	flood_fill_maps(t_game *game, char **maps, int x, int y)
{
	if (x < 0 || y < 0 || !maps[y] || x >= (int)ft_strlen(maps[y])
		|| maps[y][x] == '1' || maps[y][x] == 'V')
		return (0);
	if (maps[y][x] == 'E')
	{
		maps[y][x] = 'V';
		return (0);
	}
	maps[y][x] = 'V';
	flood_fill_maps(game, maps, x + 1, y);
	flood_fill_maps(game, maps, x - 1, y);
	flood_fill_maps(game, maps, x, y + 1);
	flood_fill_maps(game, maps, x, y - 1);
	return (1);
}

int	check_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	flood_fill_maps(game, game->map_cpy, game->player_in_x, game->player_in_y);
	while (game->map[i])
	{
		j = 0;
		while (game->map_cpy[i][j])
		{
			if (game->map_cpy[i][j] == 'E' || game->map_cpy[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ber(char *map_path)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("ERROR: INVALID MAP", 2), 0);
	ret = get_next_line(fd);
	if (ret < 0)
		return (ft_putstr_fd("ERROR: INVALID MAP", 2), 0);
	while (ret > 0)
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (ft_putstr_fd("ERROR: INVALID MAP", 2), 0);
		ret = get_next_line(fd);
	}
	close(fd);
	return (1);
}

