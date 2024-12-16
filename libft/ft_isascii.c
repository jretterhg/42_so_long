/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isacii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:18:45 by jretter           #+#    #+#             */
/*   Updated: 2024/03/28 15:07:04 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funktion zur Nachbildung von isascii
// Überprüfen, ob der ASCII-Wert des Zeichens zwischen 0 und 127 lieg

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
