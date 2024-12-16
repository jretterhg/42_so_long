/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:21:43 by jretter           #+#    #+#             */
/*   Updated: 2024/03/28 15:57:06 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funktion zur Nachbildung von isprint
// Überprüfen, ob das Zeichen ein druckbares Zeichen ist
//(ASCII-Wert zwischen 32 und 126 bzw oktal von 40..176)

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
