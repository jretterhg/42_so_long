/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:01:07 by jretter           #+#    #+#             */
/*   Updated: 2024/05/06 20:39:58 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	temp;

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
		str[len] = '0' + labs(temp % 10);
		temp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Prototyp der ft_itoa Funktion
// char	*ft_itoa(int n);

// // Funktion zum Testen der ft_itoa Implementierung
// void	test_ft_itoa(int n, const char *expected)
// {
// 	char	*result;

// 	result = ft_itoa(n);
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
// 	test_ft_itoa(0, "0");
// 	test_ft_itoa(12345, "12345");
// 	test_ft_itoa(-12345, "-12345");
// 	test_ft_itoa(INT_MAX, "2147483647");
// 	test_ft_itoa(INT_MIN, "-2147483648");
// 	return (0);
// }
