/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:55:25 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 14:14:29 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_strrchr
** Beschreibung: Sucht das letzte Vorkommen eines Zeichens in einem String.
** Parameter:
** - const char *s: Der String, in dem gesucht werden soll.
** - int c: Das zu suchende Zeichen.
** Rückgabe: Zeiger auf das letzte Vorkommen des Zeichens im String, sonst NULL.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	ch;
	char	*last_occurrence;

	last_occurrence = NULL;
	ch = (char)c;
	temp = (char *)s;
	while (*temp != '\0')
	{
		if (*temp == ch)
			last_occurrence = temp;
		temp++;
	}
	if (ch == '\0')
		return (temp);
	return (last_occurrence);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	str[] = "tripouille";
// 	int			to_find;
// 	char		*result;
// 	char		*test;

// 	to_find = 't' + 256;
// 	result = ft_strrchr(str, to_find);
// 	test = strrchr(str, to_find);
// 	printf("%c\n", to_find);
// 	printf("%s\n", result);
// 	printf("%s\n", test);
// 	return (0);
// }
