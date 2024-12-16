/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:52:22 by jretter           #+#    #+#             */
/*   Updated: 2024/12/16 17:31:41 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	validate_map_size(t_game *game);
/* ************************************************************************** */
/* Validates that all rows in the map have the same length                    */
/* ************************************************************************** */

bool	validate_row_lengths(t_game *game)
{
	int	y;
	int	row_length;

	y = 0;
	while (y < game->height)
	{
		row_length = ft_strlen(game->map[y]);
		if (game->map[y][row_length - 1] == '\n')
			row_length--;
		if (row_length != game->width)
		{
			return (false);
		}
		y++;
	}
	return (true);
}

/* ************************************************************************** */
/* Counts the number of collectibles on the map                              */
/* ************************************************************************** */
void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->collectibles = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/* Validates the overall map structure and contents                           */
/* ************************************************************************** */
bool	validate_map(t_game *game)
{
	t_map_stats	stats;

	if (!validate_row_lengths(game))
	{
		ft_printf("Error: Row has incorrect length.\n");
		return (false);
	}
	if (!validate_map_size(game))
		return (false);
	if (!validate_borders(game))
		return (false);
	if (!validate_elements(game, &stats))
		return (false);
	if (stats.player_count != 1 || stats.exit_count != 1
		|| game->collectibles == 0)
	{
		ft_printf("Error: only 1 P, only 1 E, at least 1 collectible.\n");
		return (false);
	}
	if (!perform_flood_fill(game))
	{
		ft_printf("Error: not all collectibles or the exit are not reachable.\n");
		return (false);
	}
	return (true);
}

/* ************************************************************************** */
/* Validates that the map does not exceed the maximum allowed size            */
/* ************************************************************************** */
static bool	validate_map_size(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		if ((int)ft_strlen(game->map[y]) > 1000)
		{
			ft_printf("Error: Row %d exceeds  size (1000 characters).\n", y);
			return (false);
		}
		y++;
	}
	return (true);
}
