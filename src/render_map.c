/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:12:44 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/09 19:29:17 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_map(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collect,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->door,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player,
			x * TILE_SIZE, y * TILE_SIZE);
	return (0);
}

int	render_map_2(t_game *game, int x, int y)
{
	y = 0;
	while (game->map[y])
	{
		printf("aqui fdp render 4\n");
		x = 0;
		while (game->map[x][y])
		{
			render_map(game, game->map[x][y], x, y);
			x++;
		}
		y++;
	}
	mlx_do_sync(game->mlx);
	return (0);
}

void	loading_img(t_game *game, void **img, char *path)
{
	int	x;
	int	y;

	x = TILE_SIZE;
	y = TILE_SIZE;
	img = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	if (!img)
	{
		ft_putstr_fd("Failed to load image\n", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
}
