/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:58:06 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/21 16:41:48 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_fd(int fd, char *content)
{
	char	*temp_buffer;
	int		read_bytes;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_2(content, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(content);
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[read_bytes] = '\0';
		content = ft_strjoin_2(content, temp_buffer);
	}
	free(temp_buffer);
	return (content);
}

static char	*extract_line(char *content)
{
	int		i;
	char	*result;

	i = 0;
	if (!content[i])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	result = ft_substr_2(content, 0, i + ft_endl(content));
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static char	*save_extracted_line(char *content)
{
	char	*new_content;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	new_content = malloc(sizeof(char) * (ft_strlen_2(content) - i + 1));
	if (!new_content)
		return (NULL);
	i++;
	while (content[i])
		new_content[j++] = content[i++];
	new_content[j] = '\0';
	free(content);
	return (new_content);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = read_from_fd(fd, content);
	if (!content)
		return (NULL);
	line = extract_line(content);
	content = save_extracted_line(content);
	return (line);
}
