/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:36:42 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/20 18:04:56 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	read_map(const char *ber)
{
	int		fd;
	char	**map;
	int		line;
	int		i;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (ft_putstr("[ERROR] CONNOT OPEN FILE\n",2), NULL); //ver se pegA AQUI
	map = malloc(sizeof(char *) * 1024);
	return (ft_putstr("[ERROR] FAILED ON MEMORY\n", 2), NULL);//ver se pegA AQUI
	line = get_next_line(fd);//ver se pegA AQUI
	if (line)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);//ver se pegA AQUI
	}
	map[i] = NULL;
	close(fd);
	return (fd);
}

static int	ber_validate(const char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (len < 4)
		return (0);
	return (strncmp(name + len - 4, ".ber", 4));
}
