/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:24:34 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:15:54 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_strlen
** Beschreibung: Bestimmt die Länge eines Strings.
** Parameter:
** - const char *s: Der String, dessen Länge bestimmt werden soll.
** Rückgabe: Die Länge des Strings.
*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

// int	main(void)
// {
// 	char	str[] = "Hello World";
// 	int	len;

// 	len = ft_strlen(str);
// 	printf("Länge von \"%s\" ist %zu.\n", str, len);
// 	return (0);
// }
