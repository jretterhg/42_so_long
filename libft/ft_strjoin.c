/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:31:17 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 14:20:04 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zusammenfassung der Funktion und der wichtigsten Überlegungen
// für die Implementierung von strjoin:

// 1. Funktion: strjoin
//    - Zweck: Fügt zwei gegebene Strings zu einem neuen String zusammen.
//    - Parameter:
// 		- s1: Zeiger auf den ersten String.
// 		- s2: Zeiger auf den zweiten String.
//    - Rückgabe: Zeiger auf den neuen String,
// 	der die Zusammenfügung von s1 und s2 ist.
// Bei einem Fehler wird NULL zurückgegeben.

// 2. Wichtige Überlegungen:
//
//    - Überprüfung,
// 	ob die Eingabestrings gültig sind. Wenn einer der Strings NULL ist,
// 	sollte entsprechend gehandelt werden.
//    - Bestimmung der Längen von s1 und s2,
// 	um den benötigten Speicher für den neuen String zu berechnen.
//    - Korrekte Terminierung des neuen Strings mit einem Nullzeichen ('\0'),
// 	um eine gültige C-String-Konvention zu erfüllen.
//
// 	- Effiziente Speicherverwaltung durch Allokation
// nur so viel Speicher wie nötig für den neuen String und das
// abschließende Nullzeichen.
// */
// Überprüfung der Eingabestrings
// Bestimmen der Länge von s1
// Bestimmen der Länge von s2
// Speicher für den neuen String allokieren
// Überprüfung der Speicherallokation
// Kopieren von s1 in result
// Anhängen von s2 an result
// Hinzufügen des Nullzeichens

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	if (joined_str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}
