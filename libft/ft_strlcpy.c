/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:47:31 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:16:03 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_strlcpy
** Beschreibung: Kopiert bis zu size - 1 Zeichen vom String src zum String dst,
**               zuzüglich einer Nullterminierung.
** Parameter:
** - char *dst: Ziel-String.
** - const char *src: Quell-String.
** - int size: Größe des Ziel-Buffers.
** Rückgabe: Die Gesamtlänge des Strings, den sie zu kopieren versuchte.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	src[] = "Hello World";
// 	char	dst[12];
// 	int	copied;

// 	copied = ft_strlcpy(dst, src, sizeof(dst));
// 	printf("Kopiert: %zu, dst: %s\n", copied, dst);
// 	return (0);
// }
