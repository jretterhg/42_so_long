/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:01:32 by jretter           #+#    #+#             */
/*   Updated: 2024/12/15 16:54:23 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/* Updates the player's position only once per key press                      */
/* ************************************************************************** */

void	update_player_position(t_game *game)
{
	if (game->g_key_pressed)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) && game->player_y > 0)
	{
		move_player(game, 0, -1);
		game->g_key_pressed = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& game->player_y < game->height - 1)
	{
		move_player(game, 0, 1);
		game->g_key_pressed = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) && game->player_x > 0)
	{
		move_player(game, -1, 0);
		game->g_key_pressed = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& game->player_x < game->width - 1)
	{
		move_player(game, 1, 0);
		game->g_key_pressed = true;
	}
}

/* ************************************************************************** */
/* Handles key presses                                                        */
/* ************************************************************************** */
void	handle_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	if (keydata.action == MLX_RELEASE)
	{
		game->g_key_pressed = false;
	}
}

//
/* ************************************************************************** */
/* Handles player movement based on key inputs                                */
/* ************************************************************************** */
void	handle_player_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) && game->player_y > 0)
	{
		move_player(game, 0, -1);
		game->g_key_pressed = true;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& game->player_y < game->height - 1)
	{
		move_player(game, 0, 1);
		game->g_key_pressed = true;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) && game->player_x > 0)
	{
		move_player(game, -1, 0);
		game->g_key_pressed = true;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& game->player_x < game->width - 1)
	{
		move_player(game, 1, 0);
		game->g_key_pressed = true;
	}
}

/* ************************************************************************** */
/* Handles input continuously                                                 */
/* ************************************************************************** */
void	handle_input(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
	}
	else if (!game->game_completed && !game->g_key_pressed)
	{
		handle_player_movement(game);
	}
	else if (!mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->g_key_pressed = false;
	}
}
