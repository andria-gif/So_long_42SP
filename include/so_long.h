/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:09:41 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/04 20:03:03 by arosa-di         ###   ########.fr       */
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
# include "../library/minilibx-linux/mlx_int.h"

# define TILE_SIZE 64
# define MAX_MAP_HEIGHT 100

# define WINDOW_WIDTH 64
# define WINDOW_HEIGHT 64

typedef struct s_game
{
	void		*mlx;
	int			moves_count;
	int			*moves_next;
	int			*moves_text;
	int			*imgs[5];
	void		*map;
	//int			collectibles_count;
	void		*copy_maps;
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
	t_game	*game;
}	t_map;

enum e_texture_index
{
	P_T = 0,
	F_T,
	C_T,
	E_T
};

int		ft_check_argc(int argc);
//int		ber_validate(char *name);
//char	**read_map(char *ber);
//int		ofc_check_maps(t_map *map);
int		main(void);
char	**read_map(char *ber);
char	copy_the_original_maps(char **mapsOriginal, int heigth);
int		free_copy_maps(char **grid, int heigth);
int		flod_fill_maps(t_game *game, char **maps, int x, int y);
int		ofc_check_maps(t_map *map);

#endif