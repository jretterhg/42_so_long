/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:48:31 by jretter           #+#    #+#             */
/*   Updated: 2024/05/07 09:56:33 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	size_t			len;
	unsigned int	temp;

	len = 0;
	temp = n;
	if (n <= 0)
		len = 1;
	while (temp != 0 && ++len)
		temp /= 10;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	temp = n;
	while (len--)
	{
		str[len] = '0' + (temp % 10);
		temp /= 10;
	}
	return (str);
}

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Prototyp der ft_utoa Funktion
// char	*ft_utoa(unsigned int n);

// // Funktion zum Testen der ft_utoa Implementierung
// void	test_ft_utoa(int n, const char *expected)
// {
// 	char	*result;

// 	result = ft_utoa(n);
// 	if (strcmp(result, expected) == 0)
// 	{
// 		printf("Test passed for input %d: expected '%s', got '%s'\n", n,
// 			expected, result);
// 	}
// 	else
// 	{
// 		printf("Test FAILED for input %d: expected '%s', got '%s'\n", n,
// 			expected, result);
// 	}
// 	free(result); // Annahme, dass ft_itoa Speicher dynamisch zuweist
// }

// int	main(void)
// {
// 	// Testfälle hinzufügen
// 	test_ft_utoa(0, "0");
// 	test_ft_utoa(12345, "12345");
// 	test_ft_utoa(999900, "999900");
// 	test_ft_utoa(INT_MAX, "2147483647");
// 	test_ft_utoa(INT_MIN, "-2147483648");
// 	return (0);
// }
