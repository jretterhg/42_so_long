/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:35:24 by jretter           #+#    #+#             */
/*   Updated: 2024/04/03 19:02:56 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_substr
// Prototype char *ft_substr(char const *s, unsigned int start, size_t len)
// Parameters
// s : The string from which to create the substring.
// start : The start index of the substring in the string ’s’.
// len : The maximum length of the substring.
// Return value The substring.NULL if the allocation fails.
// External functs.malloc Description Allocates(with malloc(3)) and
// 	returns a substring from the string ’s’.
// 	the substring begins at index ’start’ and is of maximum size ’len’.
// Überprüfung der Eingabeparameter
// Ermitteln der Länge des Originalstrings
// Überprüfen der Startposition und Länge
// Speicher für den Teilstring allokieren
// Überprüfung der Speicherallokation
// Extrahieren des Teilstrings
// Hinzufügen des Nullzeichens

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
