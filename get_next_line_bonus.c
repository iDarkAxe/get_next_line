/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:09:19 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/11 14:49:39 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_filler(int fd, char *backup);
char	*ft_make_line(char *buffer, char *backup);

/**
 * @brief Get the next line of a file descriptor
 *
 * @param fd
 * @return char*
 */
char	*get_next_line(int fd)
{
	static char	backup[MAX_FD][BUFFER_SIZE + 1] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_filler(fd, backup[fd]);
	if (line == NULL || line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

/**
 * @brief Main function that fills 'backup', and stops if \n is detected
 * after read of fixed size at compilation (default is 42 bytes)
 *
 * @param fd
 * @param backup
 * @return char*
 */
char	*ft_filler(int fd, char *backup)
{
	char	*buffer;
	ssize_t	read_return;

	read_return = 1;
	buffer = NULL;
	while (read_return > 0)
	{
		if (backup[0] == '\0')
		{
			read_return = read(fd, backup, BUFFER_SIZE);
			if (read_return < 0)
				return (free(buffer), NULL);
			backup[read_return] = '\0';
		}
		buffer = ft_strjoin(buffer, backup);
		if (buffer == NULL)
			return (NULL);
		backup[0] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (ft_make_line(buffer, backup));
	}
	return (buffer);
}

/**
 * @brief Build a new array containing the new line
 * and stores the rest of buffer into backup
 *
 * @param save
 * @return char*
 */
char	*ft_make_line(char *buffer, char *backup)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(buffer), NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	i = 0;
	while (buffer[j] != '\0')
		backup[i++] = buffer[j++];
	backup[i] = '\0';
	free(buffer);
	return (line);
}
