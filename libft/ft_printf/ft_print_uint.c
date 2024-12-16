/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:59:04 by jretter           #+#    #+#             */
/*   Updated: 2024/05/07 10:30:55 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int num, int *total_count)
{
	char	*str;
	int		counter;

	str = ft_utoa(num);
	if (!str)
		return (-1);
	counter = ft_putstr(str, total_count);
	free(str);
	return (counter);
}
