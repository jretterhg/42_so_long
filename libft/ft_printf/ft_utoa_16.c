/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:01:38 by jretter           #+#    #+#             */
/*   Updated: 2024/05/08 11:24:05 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa_16(unsigned long long n, int uppercase)
{
	int			len;
	char		*str;
	const char	*digits;

	len = calculate_hex_length(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (uppercase)
	{
		digits = "0123456789ABCDEF";
	}
	else
	{
		digits = "0123456789abcdef";
	}
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = digits[n % 16];
		n /= 16;
	}
	return (str);
}

int	calculate_hex_length(unsigned long long n)
{
	int	len;

	if (n == 0)
	{
		len = 1;
	}
	else
	{
		len = 0;
		while (n != 0)
		{
			n /= 16;
			len++;
		}
	}
	return (len);
}

// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// Prototyp der ft_utoa Funktion
// char	*ft_utoa_16(unsigned int n, unsigned int klein);

// // // Funktion zum Testen der ft_utoa Implementierung
// void	test_ft_utoa_16(int n, const char *expected, unsigned int uppercase)
// {
// 	char	*result;

// 	result = ft_utoa_16(n, uppercase);
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
// 	free(result);
// }

// int	main(void)
// {
// 	test_ft_utoa_16(0, "0", 0);
// 	test_ft_utoa_16(12345, "3039", 0);
// 	test_ft_utoa_16(9, "9", 0);
// 	test_ft_utoa_16(991, "3DF", 1);
// 	test_ft_utoa_16(991, "3df", 0);
// 	test_ft_utoa_16(INT_MAX, "7FFFFFFF", 1);
// 	test_ft_utoa_16(INT_MIN, "80000000", 1);
// 	test_ft_utoa_16(LONG_MIN, "–2147483647", 1);
// 	test_ft_utoa_16(ULONG_MAX, "4294967295", 1);
// 	return (0);
// }
