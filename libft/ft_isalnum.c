/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:06:58 by jretter           #+#    #+#             */
/*   Updated: 2024/04/02 15:42:32 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funktion zur Nachbildung von isalnum
// Buchstabe (A-Z, a-z) oder Ziffer (0-9)
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
