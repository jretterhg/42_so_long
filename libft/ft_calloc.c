/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:37:40 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 17:17:11 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h> // Für malloc und size_t

/*
** Funktion: ft_calloc
** Beschreibung: Allokiert Speicher für ein Array von nmemb Elementen
** der Größe size und initialisiert alle Bytes im allokieren Speicher mit Null.
** Parameter:
** - size_t nmemb: Die Anzahl der Elemente.
** - size_t size: Die Größe jedes Elements.
** Rückgabe: Ein Zeiger auf den allokierten Speicher,
	der mit Null initialisiert ist,
** oder NULL, wenn die Allokation fehlschlägt.
*/
// Vermeidung von Überlauf bei der Multiplikation

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	memory = malloc(total_size);
	if (memory)
		ft_memset(memory, 0, total_size);
	return (memory);
}
// int	main(void)
// {
// 	int		*arr;
// 	size_t	n;

// 	n = 5, i;
// 	arr = (int *)ft_calloc(n, sizeof(int));
// 	if (arr == NULL)
// 	{
// 		printf("Speicherzuweisung fehlgeschlagen\n");
// 		return (1);
// 	}
// 	// Anzeigen der Werte im Array, um zu bestätigen, dass sie alle 0 sind
// 	for (i = 0; i < n; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// 	free(arr); // Freigeben des allokierten Speichers
// 	return (0);
// }
