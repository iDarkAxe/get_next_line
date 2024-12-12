/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:04 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/12 13:33:51 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
