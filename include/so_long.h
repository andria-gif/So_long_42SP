/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:09:41 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/22 20:06:55 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/so_long.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../library/minilibx-linux/mlx.h"
# include "../library/libft/libft.h"
# include <mlx.h>

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
int		ber_validate(char *name);
char	**read_map(char *ber);
int		ofc_check_maps(t_map *map);

#endif