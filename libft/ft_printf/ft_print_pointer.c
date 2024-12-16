/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:47:20 by jretter           #+#    #+#             */
/*   Updated: 2024/05/08 11:17:37 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_null_pointer(int *total_count)
{
	int	len;

	len = ft_putstr("0x0", total_count);
	if (len < 0)
	{
		return (-1);
	}
	*total_count += len;
	return (len);
}

long	print_pointer_address(unsigned long long ptr, int *total_count)
{
	char				*hex_string;
	int					len;
	unsigned long long	addr;

	addr = ptr;
	hex_string = ft_utoa_16(addr, 0);
	if (!hex_string)
	{
		free(hex_string);
		return (-1);
	}
	len = ft_putstr("0x", total_count);
	if (len < 0)
	{
		free(hex_string);
		return (-1);
	}
	*total_count += len;
	len = ft_putstr(hex_string, total_count);
	free(hex_string);
	if (len < 0)
		return (-1);
	*total_count += len;
	return (*total_count);
}

long	ft_print_pointer(unsigned long long ptr, int *total_count)
{
	if (ptr == 0)
	{
		return (print_null_pointer(total_count));
	}
	return (print_pointer_address(ptr, total_count));
}

// // #include <stdio.h>

// // Test
// #include "ft_printf.h"
// #include <stdio.h>
// #include <stdlib.h>

// int	ft_putstr(const char *str, int *total_count)
// {
// 	int	len;

// 	len = printf("%s", str);
// 	// Simulating ft_putstr with printf for demonstration
// 	if (len > 0)
// 	{
// 		*total_count += len;
// 	}
// 	return (len);
// }

// char	*ft_utoa_16(unsigned long n, int uppercase)
// {
// 	static char	buffer[20];

// 	sprintf(buffer, "%lx", n);
// 	return (buffer);
// }

// void	test_print_pointer(void *ptr)
// {
// 	int	total_count;
// 	int	result;

// 	total_count = 0;
// 	result = ft_print_pointer(ptr, &total_count);
// 	printf(" -> Printed %d characters\n", total_count);
// 	if (result < 0)
// 	{
// 		printf("Error occurred during printing.\n");
// 	}
// }

// int	main(void)
// {
// 	int	local_variable;

// 	// Test with NULL pointer
// 	printf("Testing NULL pointer:\n");
// 	test_print_pointer(NULL);
// 	// Test with a non-null pointer (e.g., address of a local variable)
// 	local_variable = 42;
// 	printf("Testing non-NULL pointer:\n");
// 	test_print_pointer(&local_variable);
// 	// Test with a literal address (not recommended in practical scenarios)
// 	printf("Testing arbitrary memory address (0x1234):\n");
// 	test_print_pointer((void *)0x1234);
// 	return (0);
// }
