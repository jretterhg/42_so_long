/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:33:39 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 17:30:22 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  * Implementierung der ft_split Funktion:
//  * Teilt einen String `s` in Substrings, getrennt durch das Zeichen `sep`.
// 	* Jeder Substring wird in einem dynamisch allokierten arraynew von
//	Strings gespeichert.
//  * Das arraynew wird mit einem NULL-Zeiger abgeschlossen.
//  *
//  * Funktionen:
//  * - is_sep: Überprüft, ob ein Zeichen ein Separator ist.
//  * - count_words: Zählt die Anzahl der Wörter, die durch `sep` getrennt sind.
//  *
// 	- next_word_start: Findet den Start des nächsten Wortes und das Ende
//  des aktuellen Wortes.
//  *
// 	- word_length: Berechnet die Länge des aktuellen Wortes bis zum
// nächsten Separator.
//  * - extract_word: Kopiert ein Wort in einen neu allokierten Speicherbereich.

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_arraynew(size_t i, char **arraynew)
{
	while (i > 0)
	{
		i--;
		free(*(arraynew + i));
	}
	free(arraynew);
}

static char	**mysplit(char const *s, char c, char **arraynew,
		size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(arraynew + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(arraynew + i))
		{
			free_arraynew(i, arraynew);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(arraynew + i) = NULL;
	return (arraynew);
}

char	**ft_split(char const *s, char c)
{
	char	**arraynew;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arraynew = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arraynew)
		return (NULL);
	arraynew = mysplit(s, c, arraynew, words);
	return (arraynew);
}

// Test program
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*test_string = "Hello, world! This is a test string.";
// 	char		**split_result;

// 	split_result = ft_split(test_string, ' ');
// 	printf("Original string: %s\n", test_string);
// 	printf("Split result:\n");
// 	for (int i = 0; split_result[i]; i++)
// 		printf("%s\n", split_result[i]);
// 	free_split(split_result);
// 	return (0);
// }
