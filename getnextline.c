/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:01:26 by jretter           #+#    #+#             */
/*   Updated: 2024/12/16 17:26:52 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

// Function to read from file descriptor and update buffer
static char	*read_and_update_buffer(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	while (!ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (NULL);
	}
	return (remainder);
}

// Function to extract the next line and update the remainder
static char	*extract_line(char **remainder)
{
	char	*newline;
	char	*line;
	char	*new_remainder;

	if (!*remainder || **remainder == '\0')
		return (NULL);
	newline = ft_strchr(*remainder, '\n');
	if (newline)
	{
		*newline = '\0';
		line = ft_strdup(*remainder);
		new_remainder = ft_strdup(newline + 1);
	}
	else
	{
		line = ft_strdup(*remainder);
		new_remainder = NULL;
	}
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}

// Function to handle cleanup and errors
static char	*clean_up(char **remainder)
{
	if (remainder && *remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	return (NULL);
}

// Main get_next_line function
char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
	{
		remainder = ft_strdup("");
		if (!remainder)
			return (NULL);
	}
	remainder = read_and_update_buffer(fd, remainder);
	if (!remainder)
		return (clean_up(&remainder));
	line = extract_line(&remainder);
	if (!line)
		return (clean_up(&remainder));
	return (line);
}
