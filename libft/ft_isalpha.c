/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:40:06 by jretter           #+#    #+#             */
/*   Updated: 2024/04/02 15:39:36 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funktion zur Überprüfung, ob ein Zeichen ein Alphabet.Zeichen ist
// Wenn das Zeichen ein Alphabet.Zeichen ist, gibt die Funktion 1 zurück
// Wenn das Zeichen kein Alphabet ist, gibt die Funktion 0 zurück

int	ft_isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
