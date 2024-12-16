/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:52:22 by jretter           #+#    #+#             */
/*   Updated: 2024/12/15 20:32:31 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ************************************************************************** */
/* Reads a single row from the map file                                       */
/* ************************************************************************** */
// bool		g_key_pressed = false;

static bool	read_map_row(int fd, char **row, t_game *game)
{
	char	*buffer;

	buffer = get_next_line(fd);
	if (!buffer)
		return (false);
	*row = ft_strdup(buffer);
	free(buffer);
	if (!*row)
	{
		printf("Failed to duplicate row %d\n", game->height);
		return (false);
	}
	if (game->width == 0)
		game->width = ft_strlen(*row);
	return (true);
}

/* ************************************************************************** */
/* Initializes the game                                                       */
/* ************************************************************************** */
bool	initialize_game(t_game *game, const char *map_file)
{
	memset(game, 0, sizeof(t_game));
	if (!load_map(map_file, game))
		return (false);
	game->mlx = mlx_init(game->width * TILE_SIZE, game->height * TILE_SIZE,
			"So Long", true);
	if (!game->mlx)
		return (false);
	game->textures[0] = mlx_load_png("player.png");
	game->textures[1] = mlx_load_png("collectible.png");
	game->textures[2] = mlx_load_png("wall.png");
	game->textures[3] = mlx_load_png("exit.png");
	render_map(game);
	update_move_counter(game);
	return (true);
}

/* ************************************************************************** */
/* Loads the map from a file                                                  */
/* ************************************************************************** */
bool	load_map(const char *filename, t_game *game)
{
	int		fd;
	char	*row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening map file"), false);
	game->map = malloc(100 * sizeof(char *));
	if (!game->map)
		return (perror("Memory allocation failed"), close(fd), false);
	game->height = 0;
	while (game->height < 100)
	{
		if (!read_map_row(fd, &row, game))
			break ;
		game->map[game->height++] = row;
	}
	close(fd);
	if (!validate_map(game))
		return (false);
	return (true);
}

/* ************************************************************************** */
/* Main function                                                              */
/* ************************************************************************** */
int32_t	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (!initialize_game(&game, argv[1]))
		return (EXIT_FAILURE);
	mlx_key_hook(game.mlx, handle_key_press, &game);
	mlx_loop_hook(game.mlx, (void (*)(void *))handle_input, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
