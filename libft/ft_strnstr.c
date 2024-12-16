/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:27:33 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:15:32 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //
// /* Funktion: ft_strnstr
// ** Beschreibung: Sucht einen String in einem anderen
// ** String mit einer Längenbegrenzung.
// Parameter:
// ** - const char *haystack: String, in dem gesucht wird.
// ** - const char *needle: String, nach dem gesucht wird.
// ** - int len: Maximale Suchlänge.
// ** Rückgabe: Zeiger auf den Anfang des gefundenen Strings, sonst NULL.
// */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
// int	main(void)
// {
// 	char	haystack[] = "Hello World";
// 	char	needle[] = "World";
// 	char	*result;

// 	result = ft_strnstr(haystack, needle, ft_strlen(haystack));
// 	if (result)
// 		printf("Gefunden: %s\n", result);
// 	else
// 		printf("Nicht gefunden.\n");
// 	return (0);
// }
