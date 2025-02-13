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

static int	count_lines(const char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}
static int	validate_player_map(char **map)
{
    int i, j;
    int player_count = 0;

    for (i = 0; map[i] != NULL; i++)
    {
        for (j = 0; map[i][j] != '\0'; j++)
        {
            if (map[i][j] == 'P')
                player_count++;
        }
    }

    return (player_count == 1);
}
char	**read_map(const char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	int		lines;

	lines = count_lines(file);
	if (lines == -1)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	 if (!validate_player_map(map))
    {
        for (i = 0; map[i] != NULL; i++)
            free(map[i]);
        free(map);
        fprintf(stderr, "Error: The map must have exactly one player.\n");
        return (NULL);
    }
	return (map);
}
