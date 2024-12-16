/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:38:47 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:16:28 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // Für malloc

/*
** Funktion: ft_strdup
** Beschreibung: Erstellt eine neue Kopie des Strings s1 im Heap.
** Parameter:
** - const char *s1: Der String, der kopiert werden soll.
** Rückgabe: Ein Zeiger auf den neuen String, der eine Kopie von s1 ist,
** oder NULL, wenn die Allokation fehlschlägt.
*/

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (i <= len)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

// #include <stdio.h> // Für printf

// int	main(void)
// {
// 	const char	*original = "Hello, World!";
// 	char		*duplicate;

// 	duplicate = ft_strdup(original);
// 	if (duplicate == NULL)
// 	{
// 		printf("Speicherzuweisung fehlgeschlagen\n");
// 		return (1);
// 	}
// 	printf("Original: %s\n", original);
// 	printf("Duplikat: %s\n", duplicate);
// 	free(duplicate); // Freigeben des allokierten Speichers
// 	return (0);
// }
