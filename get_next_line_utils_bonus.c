/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:11:55 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/10 17:35:07 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	*ft_cpy_cat(char *pointer, char const *s1, char const *s2);

/**
 * @brief Len of string until end or to_find
 *
 * @param string
 * @return size_t len
 */
size_t	ft_strlen_until(const char *string, char to_find)
{
	size_t	count;

	count = 0;
	while (string[count] != '\0' && string[count] != to_find)
		count++;
	return (count);
}

/**
 * @brief Find first occurrence of searched_char
 *
 * @param string
 * @param searched_char
 * @return char* index of Char found
 */
char	*ft_strchr(const char *string, int searched_char)
{
	unsigned long int	i;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\0')
	{
		if (string[i] == (char)searched_char)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == (char)searched_char)
		return ((char *)&string[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*pointer;
	size_t	s2_len;

	s2_len = ft_strlen_until(s2, '\0');
	if (s1 == NULL)
	{
		s1 = malloc(s2_len);
		if (s1 == NULL)
			return (NULL);
	}
	pointer = malloc(ft_strlen_until(s1, '\0') + s2_len + 1);
	if (pointer == NULL)
		return (free(s1), NULL);
	pointer = ft_cpy_cat(pointer, s1, s2);
	free(s1);
	return (pointer);
}

static char	*ft_cpy_cat(char *pointer, char const *s1, char const *s2)
{
	size_t	index;
	size_t	s1_len;

	index = 0;
	while (s1[index] != '\0')
	{
		pointer[index] = s1[index];
		index++;
	}
	s1_len = index;
	index = 0;
	while (s2[index] != '\0')
	{
		pointer[s1_len + index] = s2[index];
		index++;
	}
	pointer[s1_len + index] = '\0';
	return (pointer);
}
