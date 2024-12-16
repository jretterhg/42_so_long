/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:27:49 by jretter           #+#    #+#             */
/*   Updated: 2024/05/08 11:27:29 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // For va_list
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c, int *anzahl);
int		ft_putstr(const char *str, int *total_count);
long	ft_print_pointer(unsigned long long ptr, int *total_count);
int		ft_print_int(int num, int *total_count);
int		ft_print_uint(unsigned int num, int *total_count);
int		ft_print_hex(unsigned long num, int uppercase, int *total_count);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_16(unsigned long long n, int uppercase);
int		calculate_hex_length(unsigned long long n);

long	print_pointer_address(unsigned long long ptr, int *total_count);
int		print_null_pointer(int *total_count);

// Main ft_printf function
int		ft_printf(const char *format, ...);

#endif // FT_PRINTF_H