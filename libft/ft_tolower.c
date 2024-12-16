/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:34:50 by jretter           #+#    #+#             */
/*   Updated: 2024/03/28 15:32:17 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_tolower
** Beschreibung: Konvertiert Großbuchstaben zu Kleinbuchstaben.
** Parameter: c - Das zu konvertierende Zeichen.
** Rückgabe: Kleinbuchstabe, falls c ein Großbuchstabe war, sonst c.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
** Testprogramm für die Funktion ft_tolower.
** Testet die Funktion mit verschiedenen Zeichen.
*/

// #include <stdio.h> // Standardbibliothek für Ein-/Ausgabeoperationen

// int	main(void)
// {
// 	char	test_chars[] = {'a', 'z', 'A', 'Z', '1', '_', 'M'};
// 	int		num_chars;
// 	int		i;

// 	num_chars = sizeof(test_chars) / sizeof(test_chars[0]);
// 	i = 0;
// 	printf("Testing ft_tolower function:\n");
// 	while (i < num_chars)
// 	{
// 		printf("Original: %c, Lowercase: %c\n", test_chars[i],
// 			ft_tolower(test_chars[i]));
// 		i++;
// 	}
// 	return (0);
// }
