/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:00:39 by arosa-di          #+#    #+#             */
/*   Updated: 2024/12/02 19:21:05 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char const *string);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_endl(char	*buffer);
char	*get_next_line(int fd);
#endif
