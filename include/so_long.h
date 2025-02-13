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

# define TILE_SIZE 32
# define MAX_MAP_HEIGHT 100

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 900
//s#define BUFFER_SIZE 1024

// Definições de teclas
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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
	int			collectibles;
	int			collectibles_count;
	int			count_player;
	int			count_exit;
	int			player_in_x;
	int			player_in_y;
	int			map_width;
	int			map_height;
	char		*map_path;
	void		*mlx_ptr;
	int			exits;
}	t_game;

// typedef struct s_map
// {
// 	char	**grid;
// 	int		width;
// 	int		height;
// 	int		collectibles_count;
// 	int		player_in_x;
// 	int		player_in_y;
// 	int		exits;
// 	char	**map;
// }	t_map;

enum e_texture_index
{
	P_T = 0,
	F_T,
	C_T,
	W_T,
	E_T
};

char	**read_map(const char *file);
void	free_copy_maps(char **copy, int height);
int		dimenssions_map(t_game *game);
void	init_game(t_game *game);
void	to_clean_game(t_game *game);
void	loading_img(t_game *game, void **img, char *path);
int		render_map_2(t_game *game);
void	download_map_2(t_game *game);
void	load_textures(t_game *game);
void	download_map_2(t_game *game);
void	loading_img(t_game *game, void **img, char *path);
void	download_img_maps(t_game *game, int tile, int x, int y);
int		player_position_y(char **map);
int		player_position_x(char **map);
int		exit_game(void *game);
void	initializer_game(t_game *game, char *map_path);
int		count_chars_game(char **map, char c);
int		flood_fill_maps(t_game *game, char **maps, int x, int y);
char	*get_next_line_1(int fd);
void	ft_putstr_fd_2(char *s, int fd);
void	load_img(t_game *game, void **img, char *path);
void	init_img(t_game *game);
int		get_map_height(t_game *game);
int		get_map_widith(t_game *game);
void	move_player(t_game *game, int x, int y);
int		handle_keypress(int keycode, t_game *game);
int		check_ber(char *map_path);
int		free_maps(char **grid, int heigth);
int		check_ber(char *map_path);
int		check_player_count(t_game *game);
int		check_line_lengths(t_game *game);
int		check_map_integrity(t_game *game);


#endif
