/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:01:26 by jretter           #+#    #+#             */
/*   Updated: 2024/12/18 19:14:12 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

/* ************************************************************************** */
/* Update buffer by reading from file descriptor                              */
/* ************************************************************************** */
static char	*update_buffer(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp;

	while (!ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			return (remainder);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		if (!temp)
		{
			free(remainder);
			return (NULL);
		}
		free(remainder);
		remainder = temp;
	}
	return (remainder);
}

/* ************************************************************************** */
/* Extract line from remainder and update it                                  */
/* ************************************************************************** */
static char	*extract_and_update_remainder(char **remainder)
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
	if (!line || (newline && !new_remainder))
		return (free(line), free(new_remainder), NULL);
	return (line);
}

/* ************************************************************************** */
/* Free remainder if needed                                                   */
/* ************************************************************************** */
static char	*free_remainder(char **remainder)
{
	if (remainder && *remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	return (NULL);
}

/* ************************************************************************** */
/* Initialize and process remainder                                           */
/* ************************************************************************** */
static char	*process_remainder(int fd, char **remainder)
{
	char	*line;

	if (!*remainder)
	{
		*remainder = ft_strdup("");
		if (!*remainder)
			return (NULL);
	}
	*remainder = update_buffer(fd, *remainder);
	if (!*remainder)
		return (free_remainder(remainder));
	line = extract_and_update_remainder(remainder);
	if (!line)
		return (free_remainder(remainder));
	return (line);
}

/* ************************************************************************** */
/* Get the next line from the file descriptor                                 */
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (process_remainder(fd, &remainder));
}
