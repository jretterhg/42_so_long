/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:26:53 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 09:54:04 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //
// /* Beschreibung: Konvertiert den String str in einen Integerwert.
// ** Die Funktion überspringt alle White-Space-Zeichen am Anfang des Strings,
// ** erkennt das Vorzeichen (positiv oder negativ) und konvertiert dann
// ** die folgenden numerischen Zeichen
// bis zum ersten nicht-numerischen Zeichen.
// ** Parameter:
// ** - const char *str: Der zu konvertierende String.
// ** Rückgabe: Der konvertierte Wert als Integer.
// */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
//#include <stdio.h> // Für printf

// int	main(void)
// {
// 	char	*strs[] = {"   -42", "123abc", "+-54", "2147483647", "-2147483648",
// 			"0"};
// 	int		i;

// 	for (i = 0; i < (int)(sizeof(strs) / sizeof(strs[0])); i++)
// 	{
// 		printf("ft_atoi(\"%s\") = %d\n", strs[i], ft_atoi(strs[i]));
// 	}
// 	return (0);
// }
