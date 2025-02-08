/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moviment_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:51:33 by arosa-di          #+#    #+#             */
/*   Updated: 2025/02/08 18:00:52 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_chars_game(char *str, char c) //função para contar os caracteres
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
