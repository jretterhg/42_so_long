/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:28:16 by jretter           #+#    #+#             */
/*   Updated: 2024/05/06 16:33:03 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Helper function to print a string and update the total count

#include "ft_printf.h"

int	ft_putstr(const char *str, int *total_count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		(*total_count)++;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*textadresse;
// 	int		counter;

// 	textadresse = "a1234";
// 	counter = printf("%s\n", textadresse);
// 	printf("%d\n", counter);
// 	counter = ft_putstr(textadresse);
// 	counter = counter + '0';
// 	write(1, "\n", 1);
// 	write(1, &counter, 1);
// 	write(1, "\n", 1);
// }
