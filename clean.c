/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:33:59 by jretter           #+#    #+#             */
/*   Updated: 2024/12/18 18:05:23 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*cleamup*/
#include "so_long.h"

void	free_map(t_game *game)
{
	int	y;

	if (!game->map)
		return ;
	y = 0;
	while (y < game->height)
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i])
			mlx_delete_texture(game->textures[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	if (game->move_counter_img)
	{
		mlx_delete_image(game->mlx, game->move_counter_img);
		game->move_counter_img = NULL;
	}
}

void	cleanup_game(t_game *game)
{
	if (game->mlx != NULL)
	{
		free_images(game);
		free_textures(game);
		free_map(game);
		mlx_terminate(game->mlx);
	}
}
