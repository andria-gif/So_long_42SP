/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:09:41 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/05 21:23:07 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/so_long.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../library/minilibx-linux/mlx.h"
# include "../library/libft/libft.h"
//#include <mlx.h>
//# include "../library/minilibx-linux/mlx_int.h"

# define TILE_SIZE 64
# define MAX_MAP_HEIGHT 100

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 900

typedef struct s_game
{
	void		*mlx;
	int			moves_count;
	int			*moves_next;
	int			*moves_text;
	int			*imgs[5];
	char		**map;
	void		*player;
	void		*collect;
	void		*door;
	void		*floor;
	int			i;
	void		*wall;
	void		*window;
	int			collectibles_count;
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
	F_T,
	C_T,
	E_T
};

int		ft_check_argc(int argc);
int		ber_validate(char *name);
char	**read_map(char *ber);
int		ofc_check_maps(t_map *map);
char	**read_map(char *ber);
char	copy_the_original_maps(char **mapsOriginal, int heigth);
void	free_copy_maps(char **copy, int height);
int		ofc_check_maps(t_map *map);
int		main_window(void);
void	init_components_maps(t_map	*map, int *p, int *e);
int		calulete_dimensions_maps(t_map	*map, int max_swidth, int max_sheight);
int		calculate_dimensions_screen_maps(t_map *map);
void	to_clean_game(t_game *game);
void	init_components_maps(t_map	*map, int *p, int *e);
void	loading_img(t_game *game, void **img, char *path);
int		render_map_2(t_game *game, int x, int y);
int		render_map(t_game *game, char tile, int x, int y);
void	load_textures(t_game *game);
void	download_map_2(t_game *game, t_map *map);
void	loading_img(t_game *game, void **img, char *path);
void	download_img_maps(t_game *game, int tile, int x, int y);
int		window(int argc, char **argv);

#endif

