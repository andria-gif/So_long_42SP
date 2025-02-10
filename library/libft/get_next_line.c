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

// static char	*read_from_fd(int fd, char *content)
// {
// 	char	*temp_buffer;
// 	int		read_bytes;

// 	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!temp_buffer)
// 		return (NULL);
// 	read_bytes = 1;
// 	while (!ft_strchr_2(content, '\n') && read_bytes != 0)
// 	{
// 		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
// 		if (read_bytes < 0)
// 		{
// 			free(content);
// 			free(temp_buffer);
// 			return (NULL);
// 		}
// 		temp_buffer[read_bytes] = '\0';
// 		content = ft_strjoin_2(content, temp_buffer);
// 	}
// 	free(temp_buffer);
// 	return (content);
// }

// static char	*extract_line(char *content)
// {
// 	int		i;
// 	char	*result;

// 	i = 0;
// 	if (!content[i])
// 		return (NULL);
// 	while (content[i] && content[i] != '\n')
// 		i++;
// 	result = ft_substr_2(content, 0, i + ft_endl(content));
// 	if (!result)
// 	{
// 		free(result);
// 		return (NULL);
// 	}
// 	return (result);
// }

// static char	*save_extracted_line(char *content)
// {
// 	char	*new_content;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (content[i] && content[i] != '\n')
// 		i++;
// 	if (!content[i])
// 	{
// 		free(content);
// 		return (NULL);
// 	}
// 	new_content = malloc(sizeof(char) * (ft_strlen_2(content) - i + 1));
// 	if (!new_content)
// 		return (NULL);
// 	i++;
// 	while (content[i])
// 		new_content[j++] = content[i++];
// 	new_content[j] = '\0';
// 	free(content);
// 	return (new_content);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*content;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	content = read_from_fd(fd, content);
// 	if (!content)
// 		return (NULL);
// 	line = extract_line(content);
// 	content = save_extracted_line(content);
// 	return (line);
// }

char	*get_next_line(int fd)
{
    static char    *rl[1024];
    char        *buffer;
    char        *line;
    char        *temp;
    int            bytes_read;

    buffer = ft_check_buffer(fd, &rl[fd]);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break ;
        rl[fd] = ft_get_temp(bytes_read, buffer, rl[fd]);
        if (ft_strchr(rl[fd], '\n'))
            break ;
    }
    free(buffer);
    if (bytes_read < 0  (bytes_read == 0 && (!rl[fd]  rl[fd][0] == '\0')))
        return (free(rl[fd]), rl[fd] = NULL);
    line = ft_extract_line(rl[fd]);
    temp = ft_strdup(rl[fd] + ft_strlen(line));
    free(rl[fd]);
    rl[fd] = temp;
    return (line);
}

char    ft_extract_line(char rl)
{
    char    *line;
    int        i;
    int        j;

    i = 0;
    while (rl[i] && rl[i] != '\n')
        i++;
    if (rl[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = rl[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}

char    *ft_check_buffer(int fd, char **rl)
{
    char    buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    if (rl == NULL)
        *rl = ft_strdup("");
    return (buffer);
}

char    ft_get_temp(int bytes_read, charbuffer, char *rl)
{
    char    *temp;

    buffer[bytes_read] = '\0';
    temp = ft_strjoin(rl, buffer);
    free(rl);
    return (temp);
}