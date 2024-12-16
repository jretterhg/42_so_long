/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:29:55 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:16:57 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Vergl die ersten n Bytes der beiden Speicher s1 und s2.
** Parameter:
** - const void *s1: Der erste Speicherbereich.
** - const void *s2: Der zweite Speicherbereich.
** - size_t n: Die Anzahl der Bytes, die verglichen werden sollen.
** Rückgabe: 0,
** wenn die Speicherbereiche identisch sind. Ein Wert kleiner als 0,
** wenn das erste nicht übereinstimmende Byte in s1 kleiner als in s2 ist.
** Ein Wert größer als 0,
	wenn das erste nicht übereinstimmende Byte in s1 größer als in s2 ist.
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1, *p2 = s2;

	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// Testprogramm für ft_memcmp
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Hello World";
// 	char	s2[] = "Hello World!";
// 	int		result;

// 	result = ft_memcmp(s1, s2, sizeof(s1));
// 	if (result > 0)
// 		printf("s1 ist größer als s2\n");
// 	else if (result < 0)
// 		printf("s1 ist kleiner als s2\n");
// 	else
// 		printf("s1 ist gleich s2\n");
// 	return (0);
// }
