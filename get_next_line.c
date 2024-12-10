/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:12:58 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/10 11:27:19 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
// TO REMOVE @TODO
#include <stdio.h>

char	*ft_filler(int fd, char *backup);
char	*ft_store_for_next_use(char *save);
char	*ft_make_line(char *line, char *backup);

/**
 * @brief Get the next line of a file descriptor
 *
 * @param fd
 * @return char*
 */
char	*get_next_line(int fd)
{
	static char	memory[BUFFER_SIZE + 1] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_filler(fd, memory);
	if (line == NULL)
		return (NULL);
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

	if (backup[0] != '\0' && 0)
		buffer = ft_strjoin(0, backup);
	else	
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_return = 1;
	while (read_return != 0)
	{
		read_return = read(fd, backup, BUFFER_SIZE);
		if (read_return == -1)
			return (free(buffer), NULL);
		backup[read_return] = '\0';
		buffer = ft_strjoin(buffer, backup);
		backup[0] = '\0';
		if (buffer == NULL)
			return(NULL);
		if (ft_strchr(buffer, '\n') != NULL)
			return (ft_make_line(buffer, backup));
	}
	return (buffer);
}

/**
 * @brief Build a new array with the save
 *
 * @param save
 * @return char*
 */
char	*ft_make_line(char *line, char *backup)
{
	size_t	i;
	size_t	backup_size;
	char	*new_line;

	if (line == NULL || line[0] == '\0')
		return (NULL);
	new_line = malloc(sizeof(char) * (ft_strlen_until(line, '\n') + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	backup_size = ft_strlen_until(backup, '\0');
	while (line[i] != '\0' && backup_size + i <= BUFFER_SIZE)
		backup[backup_size + i] = line[i];
	backup[backup_size + i] = '\0';
	return (new_line);
}
