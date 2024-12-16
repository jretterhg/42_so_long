/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:55:01 by jretter           #+#    #+#             */
/*   Updated: 2024/05/06 20:40:38 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num, int *total_count)
{
	char	*str;
	int		count;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	count = ft_putstr(str, total_count);
	free(str);
	return (count);
}
