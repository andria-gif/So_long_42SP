/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_validade.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:36:42 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/16 18:53:02 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int read_map(const char *ber)
{
    int     fd;
    char    **map;
    
    fd = open(ber, O_RDONLY );
    if (fd < 0)
    return(ft_putstr("[ERROR] CONNOT OPEN FILE\n",2),NULL);
    if (!map)
		return (ft_putstr_fd("[ERROR] FAILED ON MEMORY\n", 2), NULL);
    
}

void    read_line_maps(int fd, char **map)
{
    
}