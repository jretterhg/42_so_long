/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:42:48 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 13:55:52 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_strchr
** Beschreibung: Sucht das erste Vorkommen des Zeichens c im String s.
** Parameter:
** - const char *s: Der String, in dem gesucht wird.
** - int c: Das zu suchende Zeichen, umgewandelt in ein `char`.
** Rückgabe: Ein Zeiger auf das erste Vorkommen des Zeichens im String,
** oder NULL, wenn das Zeichen nicht gefunden wurde.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	char	ch;

	ch = (char)c;
	temp = (char *)s;
	while (*temp != '\0')
	{
		if (*temp == ch)
			return (temp);
		temp++;
	}
	if (ch == '\0')
		return (temp);
	return (NULL);
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
// 	result = ft_strchr(str, to_find);
// 	test = strchr(str, to_find);
// 	printf("%c\n", to_find);
// 	printf("%s\n", result);
// 	printf("%s\n", test);
// 	return (0);
// }
