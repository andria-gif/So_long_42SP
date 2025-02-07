/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:03:24 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/28 17:19:06 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	window(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (argc && argv)
		printf("Ok\n");
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "window");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}