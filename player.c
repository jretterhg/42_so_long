/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:45:16 by jretter           #+#    #+#             */
/*   Updated: 2024/12/07 14:27:15 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/* Handle player collectible and exit logic                                   */
/* ************************************************************************** */
void	handle_collectible_and_exit(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map[new_y][new_x];
	if (tile == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (tile == 'E')
	{
		if (game->collectibles == 0)
		{
			game->game_completed = true;
			mlx_close_window(game->mlx);
		}
	}
}

/* ************************************************************************** */
/* Moves the player                                                           */
/* ************************************************************************** */
void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	handle_collectible_and_exit(game, new_x, new_y);
	if (tile == 'E' && game->collectibles > 0)
		return ;
	if (game->game_completed)
		return ;
	game->map[game->player_y][game->player_x] = '0';
	render_tile(game, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	render_tile(game, new_x, new_y);
	game->moves++;
	update_move_counter(game);
}
