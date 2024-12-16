/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:19:39 by jretter           #+#    #+#             */
/*   Updated: 2024/12/15 19:38:04 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/* Processes a valid tile during flood fill                                   */
/* ************************************************************************** */
static void	process_tile(t_game *game, int x, int y, t_flood_fill *state)
{
	state->visited[y][x] = true;
	if (game->map[y][x] == 'C')
		state->flooded_items++;
	if (game->map[y][x] == 'E')
		state->exit_found = true;
}

/* ************************************************************************** */
/* Recursive Flood-Fill Logic                                                 */
/* ************************************************************************** */
static void	flood_fill_recursive(t_game *game, int x, int y,
		t_flood_fill *state)
{
	if (!is_valid_tile(game, x, y, state))
	{
		return ;
	}
	process_tile(game, x, y, state);
	flood_fill_recursive(game, x + 1, y, state);
	flood_fill_recursive(game, x - 1, y, state);
	flood_fill_recursive(game, x, y + 1, state);
	flood_fill_recursive(game, x, y - 1, state);
}

/* ************************************************************************** */
/* Frees the visited array for flood fill                                     */
/* ************************************************************************** */
void	free_visited(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

/* ************************************************************************** */
/* Executes Flood Fill and Validates Map Accessibility                        */
/* ************************************************************************** */
bool	perform_flood_fill(t_game *game)
{
	t_flood_fill	state;
	int				y;

	state.visited = malloc(sizeof(bool *) * game->height);
	if (!state.visited)
		return (false);
	y = 0;
	while (y < game->height)
	{
		state.visited[y] = calloc(game->width, sizeof(bool));
		if (!state.visited[y])
			return (free_visited(state.visited, y), false);
		y++;
	}
	state.flooded_items = 0;
	state.exit_found = false;
	flood_fill_recursive(game, game->player_x, game->player_y, &state);
	// Debug: Ergebnisse des Flood-Fill
	// Visited-Array freigeben
	free_visited(state.visited, game->height);
	// Überprüfen, ob alle Sammelobjekte und der Ausgang erreichbar sind
	if (state.flooded_items != game->collectibles || !state.exit_found)
		return (false);
	return (true);
}

bool	is_valid_tile(t_game *game, int x, int y, t_flood_fill *state)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
	{
		return (false);
	}
	if (state->visited[y][x])
	{
		return (false);
	}
	if (game->map[y][x] == '1')
	{
		return (false);
	}
	return (true);
}
