/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:18:09 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:25:31 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
//  * ft_strtrim - Entfernt alle Zeichen aus 'set' vom Anfang und Ende von 's1'.
//  *
//  * Beschreibung:
//  * - Diese Funktion erstellt eine Kopie von 's1',
// ohne die Zeichen am Anfang und Ende, die in 'set' enthalten sind.
//  * - Die Funktion verwendet strchr, um zu überprüfen,
// ob ein Zeichen in 'set' enthalten ist.
//  * - Sie gibt einen Zeiger auf den neuen,
// getrimmten String zurück oder NULL bei einem Fehler.
//  */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	size_t	i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trimmed_str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed_str[i] = s1[start];
		i++;
		start++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
