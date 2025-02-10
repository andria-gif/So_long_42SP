/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:29:17 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 20:29:11 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_textures(t_game *game) //função para carregar as texturas
{
	int	size;

	size = 32;
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &size, &size);
	game->door = mlx_xpm_file_to_image(game->mlx,
			"./textures/door.xpm", &size, &size);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm", &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &size, &size);
	if (!game->player || !game->door || !game->collect
		|| !game->floor || !game->wall)
	{
		ft_putstr_fd("Error\nTextures not loaded\n", 2);
		exit(1);
	}
}

void	download_img_maps(t_game *game, int tile, int x, int y)
{
	if (tile == -1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->floor, y * TILE_SIZE, x * TILE_SIZE);
	else if (tile == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game-> wall, y * TILE_SIZE, x * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game-> player, y * TILE_SIZE, x * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collect, y * TILE_SIZE, x * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->door, y * TILE_SIZE, x * TILE_SIZE);
}

void	download_map_2(t_game *game) //função bi dimensional para alocar as imagens no mapa
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			download_img_maps(game, game->map[x][y], x, y);
			x++;
		}
		y++;
	}
	mlx_do_sync(game->mlx);
}

void	load_img(t_game *game, void **img, char *path) //funçã
{
	int	img_x;
	int	img_y;

	img_x = TILE_SIZE;
	img_y = TILE_SIZE;
	*img = mlx_xpm_file_to_image(game->mlx , path ,&img_x, &img_y);
	if (!img)
	{
		write(2, "Error: Failed to load ", 24);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(1);
	}
}

void	init_img(t_game *game)
{
	// load_img(game, &game->player, "./textures/player.xpm");
	// load_img(game, &game->door, "./textures/door.xpm");
	// load_img(game, &game->collect, "./textures/collect.xpm");
	// load_img(game, &game->floor , "./textures/floor.xpm");
	// load_img(game, &game->wall ,"./textures/wall.xpm");
	load_img(game,(void **) &game->player, "./textures/player.xpm");
	load_img(game,(void **) &game->door, "./textures/door.xpm");
	load_img(game,(void **) &game->collect, "./textures/collect.xpm");
	load_img(game,(void **) &game->floor, "./textures/floor.xpm");
	load_img(game,(void **) &game->wall, "./textures/wall.xpm");
}

