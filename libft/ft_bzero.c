/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:40:20 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 18:17:25 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funktion zur Nachbildung von bzero
// Deklaration der Zeiger und Variablen
// Zeiger auf char
// Initialisierung des Zeigers auf den Anfang der Speicheradresse
// Durchlaufen des Speicherbereichs und Setzen jedes Bytes auf 0
// Setzen des aktuellen Bytes auf 0
// Bewegen des Zeigers zum nächsten Byte im Speicher
#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	char	*char_ptr;
	size_t	i;

	char_ptr = (char *)ptr;
	i = 0;
	while (i < num)
	{
		*char_ptr = 0;
		char_ptr++;
		i++;
	}
}
