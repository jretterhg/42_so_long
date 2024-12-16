/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:52:12 by jretter           #+#    #+#             */
/*   Updated: 2024/03/28 15:32:23 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Funktion: ft_toupper
** Beschreibung: Konvertiert Kleinbuchstaben zu Großbuchstaben.
** Parameter: c - Das zu konvertierende Zeichen.
** Rückgabe: Großbuchstabe, falls c ein Kleinbuchstabe war, sonst c.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
** Testprogramm für die Funktion ft_toupper.
** Testet die Funktion mit verschiedenen Zeichen.
*/

// int	main(void)
// {
// 	char test_chars[] = {'a', 'z', 'A', 'Z', '1', '_', 'm'};
// 	int num_chars = sizeof(test_chars) / sizeof(test_chars[0]);
// 	int i = 0;

// 	printf("Testing ft_toupper function:\n");
// 	while (i < num_chars)
// 	{
// 		printf("Original: %c, Uppercase: %c\n", test_chars[i],
// 			ft_toupper(test_chars[i]));
// 		i++;
// 	}
// 	return (0);
// }