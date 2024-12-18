/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:29:44 by jretter           #+#    #+#             */
/*   Updated: 2024/12/18 18:02:08 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/* Function to create an RGBA pixel value                                     */
/* ************************************************************************** */
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
extern void	handle_input(t_game *game);
/* ************************************************************************** */
/* Draw the background for a single tile                                      */
/* ************************************************************************** */

void	draw_background(mlx_t *mlx, int x, int y)
{
	mlx_image_t	*background;
	int			i;
	int			j;
	uint32_t	color;

	background = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	color = ft_pixel(255, 255, 255, 255);
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_put_pixel(background, i, j, color);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, background, x * TILE_SIZE, y * TILE_SIZE);
}

/* ************************************************************************** */
/* Render a single tile based on its type                                     */
/* ************************************************************************** */
void	render_tile(t_game *game, int x, int y)
{
	char		tile;
	mlx_image_t	*img;

	tile = game->map[y][x];
	img = NULL;
	draw_background(game->mlx, x, y);
	if (tile == '1')
		img = mlx_texture_to_image(game->mlx, game->textures[2]);
	else if (tile == 'E')
		img = mlx_texture_to_image(game->mlx, game->textures[3]);
	else if (tile == 'C')
		img = mlx_texture_to_image(game->mlx, game->textures[1]);
	if (img)
		mlx_image_to_window(game->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
}

/* ************************************************************************** */
/* Render the entire map                                                      */
/* ************************************************************************** */
void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(game->mlx, game->textures[0]);
	if (img)
		mlx_image_to_window(game->mlx, img, game->player_x * TILE_SIZE,
			game->player_y * TILE_SIZE);
}
