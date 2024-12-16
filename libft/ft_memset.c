/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:33:22 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:16:48 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funktion zur Nachbildung von memset
// Zeiger auf char
// Schleifenindex
// Durchlaufen des Speicherbereichs und Setzen  auf den angegebenen Wert
// Setzen des aktuellen Bytes auf den angegebenen Wert
// Rückgabe des ursprünglichen Zeigers
// Bewegen des Zeigers zum nächsten Byte im Speicher
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[50] = "Hello World";

// 	ft_memset(str + 6, '.', 5);
// 	printf("Ergebnis: %s\n", str);
// 	return (0);
// }
