/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:09:41 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/16 17:29:02 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/lib/libft.a"

# define TILE_SIZE 64
# define MAX_MAP_HEIGHT 100

typedef struct s_game
{
	mlx_t		*mlx;
	int			moves_count;
	mlx_image_t	*moves_text;
	mlx_image_t	*imgs[5];
	t_map		*map;
}	t_game;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles_count;
	int		player_in_x;
	int		player_in_y;
	int		exits;
}	t_map;

enum e_texture_index
{
	P_T = 0,
	W_T,
	F_T,
	C_T,
	E_T
};

#endif