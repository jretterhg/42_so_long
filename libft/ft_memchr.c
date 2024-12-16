/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:29:25 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:17:03 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_memchr
** Beschreibung: Sucht nach dem ersten Vorkommen des Zeichens c
** in den ersten n Bytes des Speicherbereichs s.
** Parameter:
** - const void *s: Der Speicherbereich, der durchsucht wird.
** - int c: Das zu suchende Zeichen.
** - size_t n: Die Anzahl der Bytes, die durchsucht werden sollen.
** Rückgabe: Ein Zeiger auf das gefundene Zeichen im Speicherbereich s,
** sonst NULL, wenn das Zeichen nicht gefunden wurde.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (0);
}

// Testprogramm für ft_memchr
// #include <stdio.h>

// int	main(void)
// {
// 	const char	str[] = "Hello World";
// 	char		c;
// 	char		*result;

// 	c = 'o';
// 	result = ft_memchr(str, c, sizeof(str));
// 	if (result)
// 		printf("Gefunden: '%c' in \"%s\" an Position %ld\n", c, str, result
// 			- str);
// 	else
// 		printf("Zeichen '%c' nicht gefunden.\n", c);
// 	return (0);
// }
