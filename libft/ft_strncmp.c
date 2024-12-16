/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:35:17 by jretter           #+#    #+#             */
/*   Updated: 2024/04/03 19:05:45 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_strncmp
** Beschreibung: Vergleicht  n Zeichen zweier Strings s1 und s2.
** Parameter:
** - const char *s1: Der erste String zum Vergleichen.
** - const char *s2: Der zweite String zum Vergleichen.
** - size_t n: Die maximale Anzahl an Zeichen, die verglichen werden sollen.
** Rückgabe: Ein Int-Wert, der weniger als, gleich oder größer als 0 ist,
** wenn s1 entsprechend kleiner als, gleich oder größer als s2 ist.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Hello World";
// 	char	s2[] = "Hello World!";
// 	int		result;

// 	result = ft_strncmp(s1, s2, 12);
// 	// Vergleich von mehr Zeichen als s1 enthält
// 	if (result > 0)
// 		printf("'%s' ist größer als '%s'\n", s1, s2);
// 	else if (result < 0)
// 		printf("'%s' ist kleiner als '%s'\n", s1, s2);
// 	else
// 		printf("'%s' ist gleich '%s'\n", s1, s2);
// 	result = ft_strncmp(s1, s2, 11); // Vergleich von genau 11 Zeichen
// 	if (result > 0)
// 		printf("Nach 11 Zeichen ist '%s' größer als '%s'\n", s1, s2);
// 	else if (result < 0)
// 		printf("Nach 11 Zeichen ist '%s' kleiner als '%s'\n", s1, s2);
// 	else
// 		printf("Nach 11 Zeichen ist '%s' gleich '%;
// }
