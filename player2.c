/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:45:16 by jretter           #+#    #+#             */
/*   Updated: 2024/12/18 19:05:00 by jretter          ###   ########.fr       */
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
/* Update player's old position                                               */
/* ************************************************************************** */
void	update_old_position(t_game *game)
{
	char	current_tile;

	current_tile = game->map[game->player_y][game->player_x];
	if (current_tile == 'E')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	render_tile(game, game->player_x, game->player_y);
}

/* ************************************************************************** */
/* Handle exit logic                                                          */
/* ************************************************************************** */
int	handle_exit(t_game *game, int new_x, int new_y)
{
	char	target_tile;
	//char	current_tile;

	//current_tile = game->map[game->player_y][game->player_x];
	target_tile = game->map[new_y][new_x];
	if (target_tile == 'E' && game->collectibles > 0)
	{
		update_old_position(game);
		game->player_x = new_x;
		game->player_y = new_y;
		render_tile(game, new_x, new_y);
		return (1);
	}
	if (target_tile == 'E' && game->collectibles == 0)
	{
		update_old_position(game);
		game->game_completed = true;
		mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/* Handle player movement logic                                               */
/* ************************************************************************** */
void	handle_move(t_game *game, int new_x, int new_y)
{
	char	target_tile;

	target_tile = game->map[new_y][new_x];
	if (target_tile == '1')
		return ;
	if (handle_exit(game, new_x, new_y))
		return ;
	update_old_position(game);
	game->player_x = new_x;
	game->player_y = new_y;
	handle_collectible_and_exit(game, new_x, new_y);
	game->map[new_y][new_x] = 'P';
	render_tile(game, new_x, new_y);
	game->moves++;
	update_move_counter(game);
}

/* ************************************************************************** */
/* Moves the player                                                           */
/* ************************************************************************** */
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	handle_move(game, new_x, new_y);
	render_map(game);
	render_player(game);
}
