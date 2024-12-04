/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:04 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/27 18:20:59 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

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

/**
 * @brief Allocate a new array, 
 * and return the result of s2 concatenated after s1
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*pointer;
	size_t	len;
	size_t	s1_len;
	size_t	index;

	index = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	s1_len = ft_strlen_until(s1, '\0');
	len = s1_len + ft_strlen_until(s2, '\0');
	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (free(s1), NULL);
	while (s1[index] != '\0')
	{
		pointer[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index] != '\0' && index < len - s1_len)
	{
		pointer[index + s1_len] = s2[index];
		index++;
	}
	pointer[index + s1_len] = '\0';
	return (free(s1), pointer);
}
