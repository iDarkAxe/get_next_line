/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:12:58 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/27 18:26:26 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
// TO REMOVE @TODO
#include <stdio.h>

char	*ft_filler(int fd, char *backup);
char	*ft_store_for_next_use(char *save);
char	*ft_make_line(char *save);

/**
 * @brief Get the next line of a file descriptor
 *
 * @param fd
 * @return char*
 */
char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = ft_filler(fd, memory);
	if (memory == NULL)
		return (free(memory), NULL);
	line = ft_make_line(memory);
	memory = ft_store_for_next_use(memory);
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
	int		read_return;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	read_return = 1;
	while (read_return != 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
			return (free(buffer), free(backup), NULL);
		buffer[read_return] = '\0';
		backup = ft_strjoin(backup, buffer);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	free(buffer);
	return (backup);
}

/**
 * @brief Build a new array with the save
 * 
 * @param save 
 * @return char* 
 */
char	*ft_make_line(char *save)
{
	int		i;
	char	*line;

	if (save == NULL || save[0] == '\0')
		return (NULL);
	i = ft_strlen_until(save, '\n');
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/**
 * @brief Store the rest of the array that has been unused
 * 
 * @param save 
 * @return char* 
 */
char	*ft_store_for_next_use(char *save)
{
	int		index;
	int		rest;
	char	*new_save;

	index = ft_strlen_until(save, '\n');
	if (save[index] == '\0' || save[index + 1] == '\0')
		return (free(save), NULL);
	rest = ft_strlen_until(save, '\0') - index;
	new_save = (char *)malloc(sizeof(char) * (rest));
	if (new_save == NULL)
		return (free(save), NULL);
	index++;
	rest = 0;
	while (save[index] != '\0')
		new_save[rest++] = save[index++];
	new_save[rest] = '\0';
	free(save);
	return (new_save);
}
