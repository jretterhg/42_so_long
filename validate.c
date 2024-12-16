/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:32:09 by jretter           #+#    #+#             */
/*   Updated: 2024/12/15 19:36:29 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/* Validates individual elements in the map row                              */
/* ************************************************************************** */
typedef struct s_tile_context
{
	t_game	*game;
	int		x;
	int		y;
	char	tile;
}			t_tile_context;

static bool	validate_tile(t_tile_context *ctx, t_map_stats *stats)
{
	if (ctx->tile == 'P')
	{
		ctx->game->player_x = ctx->x;
		ctx->game->player_y = ctx->y;
		stats->player_count++;
	}
	else if (ctx->tile == 'E')
	{
		stats->exit_count++;
	}
	else if (ctx->tile == 'C')
	{
		ctx->game->collectibles++;
	}
	else if (ctx->tile != '0' && ctx->tile != '1')
	{
		ft_printf("Error: Invalid character '%c' in map.\n", ctx->tile);
		return (false);
	}
	return (true);
}

/* ************************************************************************** */
/* Validates that the map contains valid elements                            */
/* ************************************************************************** */
bool	validate_elements(t_game *game, t_map_stats *stats)
{
	int				x;
	int				y;
	t_tile_context	ctx;

	y = 0;
	stats->player_count = 0;
	stats->exit_count = 0;
	ctx.game = game;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			ctx.x = x;
			ctx.y = y;
			ctx.tile = game->map[y][x];
			if (!validate_tile(&ctx, stats))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

/* ************************************************************************** */
/* Helper to validate borders of the map                                     */
/* ************************************************************************** */
static bool	validate_row_borders(char *row, int width, char position)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if ((position == 'T' || position == 'B') && row[i] != '1')
		{
			ft_printf("Error: Top/Bottom border must be walls and rect.\n");
			return (false);
		}
		if (position == 'L' && (row[0] != '1' || row[width - 1] != '1'))
		{
			ft_printf("Error: map open.\n");
			return (false);
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */
/* Validates that the map is surrounded by walls                             */
/* ************************************************************************** */
bool	validate_borders(t_game *game)
{
	int	y;

	y = 0;
	if (!validate_row_borders(game->map[0], game->width, 'T')
		|| !validate_row_borders(game->map[game->height - 1], game->width, 'B'))
		return (false);
	while (y < game->height)
	{
		if (!validate_row_borders(game->map[y], game->width, 'L'))
			return (false);
		y++;
	}
	return (true);
}
