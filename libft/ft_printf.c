/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:27:53 by jretter           #+#    #+#             */
/*   Updated: 2024/05/08 11:22:01 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char **format, va_list args, int *total_count)
{
	char	specifier;
	int		count;

	specifier = *(*format)++;
	if (specifier == 'c')
		count = ft_putchar(va_arg(args, int), total_count);
	else if (specifier == 's')
		count = ft_putstr(va_arg(args, char *), total_count);
	else if (specifier == 'd' || specifier == 'i')
		count = ft_print_int(va_arg(args, int), total_count);
	else if (specifier == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long long int),
				total_count);
	else if (specifier == 'u')
		count = ft_print_uint(va_arg(args, unsigned int), total_count);
	else if (specifier == 'x' || specifier == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), specifier == 'X',
				total_count);
	else if (specifier == '%')
		count = ft_putchar('%', total_count);
	else
		count = ft_putchar(specifier, total_count);
	if (count == -1)
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_count;

	total_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (handle_format(&format, args, &total_count) < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(*format++, &total_count) < 0)
			{
				va_end(args);
				return (-1);
			}
		}
	}
	va_end(args);
	return (total_count);
}

// int	ft_print_hex(unsigned long num, int uppercase, int *total_count)
// {
// 	char	*str;
// 	int		result;

// 	if (num < 0)
// 	{
// 		num = (unsigned int)(-num);
// 	}
// 	str = ft_utoa_16(num, uppercase);
// 	if (!str)
// 		return (-1);
// 	result = ft_putstr(str, total_count);
// 	free(str);
// 	return (result);
// }
// int	ft_print_int(int num, int *total_count)
// {
// 	char	*str;
// 	int		count;

// 	str = ft_itoa(num);
// 	if (!str)
// 		return (-1);
// 	count = ft_putstr(str, total_count);
// 	free(str);
// 	return (count);
// }

// int	print_null_pointer(int *total_count)
// {
// 	int	len;

// 	len = ft_putstr("0x0", total_count);
// 	if (len < 0)
// 	{
// 		return (-1);
// 	}
// 	*total_count += len;
// 	return (len);
// }

// long	print_pointer_address(unsigned long long ptr, int *total_count)
// {
// 	char		*hex_string;
// 	int			len;
// 	long long	addr;

// 	addr = ptr;
// 	hex_string = ft_utoa_16(addr, 0);
// 	if (!hex_string)
// 	{
// 		free(hex_string);
// 		return (-1);
// 	}
// 	len = ft_putstr("0x", total_count);
// 	if (len < 0)
// 	{
// 		free(hex_string);
// 		return (-1);
// 	}
// 	*total_count += len;
// 	len = ft_putstr(hex_string, total_count);
// 	free(hex_string);
// 	if (len < 0)
// 		return (-1);
// 	*total_count += len;
// 	return (*total_count);
// }

// long	ft_print_pointer(unsigned long long ptr, int *total_count)
// {
// 	if (ptr == 0)
// 	{
// 		return (print_null_pointer(total_count));
// 	}
// 	return (print_pointer_address(ptr, total_count));
// }

// int	ft_print_uint(unsigned int num, int *total_count)
// {
// 	char	*str;
// 	int		counter;

// 	str = ft_utoa(num);
// 	if (!str)
// 		return (-1);
// 	counter = ft_putstr(str, total_count);
// 	free(str);
// 	return (counter);
// }

// int	ft_putchar(char c, int *total_count)
// {
// 	if (write(1, &c, 1) == -1)
// 		return (-1);
// 	(*total_count)++;
// 	return (0);
// }
// int	ft_putstr(const char *str, int *total_count)
// {
// 	int	i;

// 	i = 0;
// 	if (str == NULL)
// 	{
// 		str = "(null)";
// 	}
// 	while (str[i] != '\0')
// 	{
// 		if (write(1, &str[i], 1) == -1)
// 			return (-1);
// 		(*total_count)++;
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_utoa_16(unsigned long long n, int uppercase)
// {
// 	int			len;
// 	char		*str;
// 	const char	*digits;

// 	len = calculate_hex_length(n);
// 	str = (char *)malloc(len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	if (uppercase)
// 	{
// 		digits = "0123456789ABCDEF";
// 	}
// 	else
// 	{
// 		digits = "0123456789abcdef";
// 	}
// 	str[len] = '\0';
// 	while (len > 0)
// 	{
// 		len--;
// 		str[len] = digits[n % 16];
// 		n /= 16;
// 	}
// 	return (str);
// }

// int	calculate_hex_length(unsigned long long n)
// {
// 	int	len;

// 	if (n == 0)
// 	{
// 		len = 1;
// 	}
// 	else
// 	{
// 		len = 0;
// 		while (n != 0)
// 		{
// 			n /= 16;
// 			len++;
// 		}
// 	}
// 	return (len);
// }

// char	*ft_utoa(unsigned int n)
// {
// 	char			*str;
// 	size_t			len;
// 	unsigned int	temp;

// 	len = 0;
// 	temp = n;
// 	if (n <= 0)
// 		len = 1;
// 	while (temp != 0 && ++len)
// 		temp /= 10;
// 	str = (char *)malloc(len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	str[len] = '\0';
// 	temp = n;
// 	while (len--)
// 	{
// 		str[len] = '0' + (temp % 10);
// 		temp /= 10;
// 	}
// 	return (str);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	size_t	len;
// 	long	temp;

// 	len = 0;
// 	temp = n;
// 	if (n <= 0)
// 		len = 1;
// 	while (temp != 0 && ++len)
// 		temp /= 10;
// 	str = (char *)malloc(len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	str[len] = '\0';
// 	temp = n;
// 	while (len--)
// 	{
// 		str[len] = '0' + labs(temp % 10);
// 		temp /= 10;
// 	}
// 	if (n < 0)
// 		str[0] = '-';
// 	return (str);
// }

// #include "ft_printf.h"
// #include "stdio.h"

// int	main(void)
// {
// 	int		x;
// 	int		counter;
// 	int		counterft;
// 	char	*pointer;

// 	pointer = "Hallo";
// 	// Test %c
// 	counterft = ft_printf("%c\n", 'A');
// 	printf("%d\n", counterft);
// 	counter = printf("%c\n", 'A');
// 	printf("%d\n", counter);
// 	// // Test %s
// 	counterft = ft_printf("%s\n", "Hello, World!");
// 	printf("%d\n", counterft);
// 	counter = printf("%s\n", "Hello, World!");
// 	printf("%d\n", counter);
// 	// Test %p
// 	x = 42;
// 	ft_printf("Pointer: %p\n", pointer);
// 	printf("Pointer: %p\n", pointer);
// 	// Test %d and %i
// 	ft_printf("Decimal: %d, Integer: %i\n", -123, -123);
// 	printf("Decimal: %d, Integer: %i\n", -123, -123);
// 	// Test %u
// 	counter = ft_printf("Unsigned: %u\n", 4294967295u);
// 	printf("%d\n", counter);
// 	counter = printf("Unsigned: %u\n", 4294967295u);
// 	printf("%d\n", counter);
// 	// Test %x and %X
// 	ft_printf("Hex: %x, HEX: %X\n", 255, 255);
// 	printf("Hex: %x, HEX: %X\n", 255, 255);
// 	// Test %%
// 	ft_printf("Percent: %%\n");
// 	printf("Percent: %%\n");
// 	return (0);
// }
