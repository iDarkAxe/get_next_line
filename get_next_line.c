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

/**
 * @brief Create a copy of source into a new pointer of size len
 *	NEEDS to be freed
 * @param source
 * @return char*
 */
char	*ft_strndup(const char *source, size_t len)
{
	char	*pointer;
	size_t	index;

	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		pointer[index] = source[index];
		index++;
	}
	pointer[len] = '\0';
	return (pointer);
}

#include <string.h>

/**
 * @brief Get the next line of a file descriptor
 *
 * @param fd
 * @return char*
 */
char	*get_next_line(int fd)
{
	char		ptr[BUFFER_SIZE + 1];
	static char	ptr2[BUFFER_SIZE + 1];
	size_t		index;

	index = 0;
	read(fd, ptr, BUFFER_SIZE);
	while (ptr[index] != '\0' && ptr[index] != '\n')
		index++;
	memcpy(ptr2, &ptr[index], BUFFER_SIZE - index);
	return (ft_strndup(ptr, index));
	// verify fd
	// remplir stock
	// checker buffer size <= 0
	// return (NULL), si erreur, ou fichier finis
}

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*handler;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	do
	{
		handler = get_next_line(fd);
		printf("%s\n", handler);
	} while (handler != NULL);
}
