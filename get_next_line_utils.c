/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:04 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/05 13:49:48 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

const char	*ft_strchr(const char *string, int searched_char);

/**
 * @brief Find first occurrence of searched_char
 *
 * @param string String to search in
 * @param searched_char Char to search
 * @return char* index of Char found
 */
const char	*ft_strchr(const char *string, int searched_char)
{
	unsigned long int	i;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\0')
	{
		if (string[i] == (char)searched_char)
			return (&string[i]);
		i++;
	}
	if (string[i] == (char)searched_char)
		return (&string[i]);
	return (NULL);
}
