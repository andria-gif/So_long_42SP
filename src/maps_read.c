/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:36:42 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/22 12:25:01 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	ber_validate(char *name)
// {
// 	size_t	len;

// 	len = ft_strlen(name);
// 	if (len < 4)
// 		return (0);
// 	return (ft_strncmp(name + len - 4, ".ber", 4) == 0);
// }

char	**read_map(char *ber)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	// if (!ber_validate(ber))
	// 	return (ft_putstr_fd("[ERROR] INVALID FILE FORMAT .ber\n", 2), NULL);
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("[ERROR] CANNOT OPEN FILE\n", 2), NULL);
	map = malloc(sizeof(char *) * 1024);
	if (!map)
		return (ft_putstr_fd("[ERROR] FAILED ON MEMORY\n", 2), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
