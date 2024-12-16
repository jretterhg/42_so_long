/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:49:00 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:16:08 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Beschreibung: Hängt String src an das Ende von dst an.
/*  Es werden bis zu dstsize	- strlen(dst) - 1 Zeichen
** angehängt, zuzüglich einer Nullterminierung.
** Parameter:
** - char *dst: Ziel-String, an den angehängt wird.
** - const char *src: Quell-String, der angehängt wird.
** - size_t dstsize: Größe des Ziel-Buffers.
** Rückgabe: Die Gesamtlänge des Strings, den sie zu erzeugen versuchte.
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len)
	{
		ft_strlcpy(dst + dst_len, src, src_len + 1);
	}
	else
	{
		ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	}
	return (dst_len + src_len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	dst[20] = "Hello";
// 	char	src[] = " World";
// 	size_t	cat;

// 	cat = ft_strlcat(dst, src, sizeof(dst));
// 	printf("Ergebnis: %zu, dst: %s\n", cat, dst);
// 	return (0);
// }
