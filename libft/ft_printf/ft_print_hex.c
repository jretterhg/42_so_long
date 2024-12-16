/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:01:38 by jretter           #+#    #+#             */
/*   Updated: 2024/05/06 21:21:32 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long num, int uppercase, int *total_count)
{
	char	*str;
	int		result;

	if (num < 0)
	{
		num = (unsigned int)(-num);
	}
	str = ft_utoa_16(num, uppercase);
	if (!str)
		return (-1);
	result = ft_putstr(str, total_count);
	free(str);
	return (result);
}
