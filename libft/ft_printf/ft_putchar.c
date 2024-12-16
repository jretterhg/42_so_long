/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:41:28 by jretter           #+#    #+#             */
/*   Updated: 2024/05/06 16:30:57 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Funktion schreibt ein einzelnes Zeichen und aktualisiert den Gesamtzähler
int	ft_putchar(char c, int *total_count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*total_count)++;
	return (0);
}

// int	ft_putstr(char *str)
// {
// 	int	char_counter;
// 	int	*error_ptr;

// 	*error_ptr = 0;
// 	char_counter = 0;
// 	if (str == NULL)
// 		str = "(null)";
// 	while (*str != '\0')
// 	{
// 		ft_putchar(*str, error_ptr);
// 		if (*error_ptr == -1)
// 			return (*error_ptr);
// 		str++;
// 		char_counter++;
// 	}
// 	return (char_counter);
// }

// int	main(void)
// {
// 	char	*textadresse;
// 	int		counter;

// 	textadresse = "a1234";
// 	counter = printf("%s\n", textadresse);
// 	printf("%d\n", counter);
// 	counter = ft_putstr(textadresse);
// 	// errorcode = ft_putchar(textadresse, &counter);
// 	counter = counter + '0';
// 	write(1, "\n", 1);
// 	write(1, &counter, 1);
// 	write(1, "\n", 1);
// }
