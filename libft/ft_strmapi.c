/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:30:07 by jretter           #+#    #+#             */
/*   Updated: 2024/04/04 10:02:32 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function name ft_strmapi Prototype char *ft_strmapi(char const *s,
// 	char (*f)(unsigned int, char));
// Turn in files
// 	- Parameters s : The string on which to iterate.
//     f: The function to apply to each character.
//     Return value The string created from the successive applications of ’f’.
//     Returns NULL if the allocation fails.
//     External functs.malloc Description Applies the function ’f’
//     to each character of the string ’s’,
// 			and passing its index as first argument to create a
//      new string(with malloc(3)) resulting from successive
//      applications of ’f’.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_strdup(s);
	if (!s || !f || !str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
