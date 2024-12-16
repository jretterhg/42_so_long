/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:39:39 by jretter           #+#    #+#             */
/*   Updated: 2024/12/15 20:44:34 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef SO_LONG_H
// # define SO_LONG_H

// # include "MLX42/include/MLX42/MLX42.h"
// # include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>

// /* Constants */
// # define TILE_SIZE 64

// /* Game State Structure */
// typedef struct s_game
// {
// 	char **map; // 2D array of the map
// 	bool	g_key_pressed;
// 	int width;                     // Width of the map
// 	int height;                    // Height of the map
// 	int player_x;                  // Player's X position
// 	int player_y;                  // Player's Y position
// 	int collectibles;              // Number of collectibles
// 	int moves;                     // Number of moves
// 	bool game_completed;           // Game completion state
// 	mlx_t *mlx;                    // MLX42 instance
// 	mlx_texture_t *textures[4];    // Array of textures
// 	mlx_image_t *move_counter_img; // Move counter display
// }			t_game;

// /* Global Variables */
// extern bool keys_pressed[512]; // Tracks the state of pressed keys

// /* Function Prototypes */

// /* Map Validation */
// bool		validate_map(t_game *game);
// void		count_collectibles(t_game *game);
// bool		validate_borders(t_game *game);
// bool		validate_elements(t_game *game, int *player_count, int *exit_count);
// bool		initialize_game(t_game *game, const char *map_file);
// void		handle_collectible_and_exit(t_game *game, int new_x, int new_y);
// void		move_player(t_game *game, int dx, int dy);

// /* Flood-Fill Utilities */
// void		free_visited(bool **visited, int height);

// /* Rendering */
// void		render_map(t_game *game);
// void		update_move_counter(t_game *game);
// void		render_tile(t_game *game, int x, int y);

// /* Input Handling */
// void		handle_input(t_game *game);
// void		move_player(t_game *game, int dx, int dy);
// void		handle_key_press(mlx_key_data_t keydata, void *param);
// void		update_player_position(t_game *game);

// /* Pixel Utility */
// int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// /* Map Loading */
// bool		load_map(const char *filename, t_game *game);

// #endif
#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

/* Constants */
# define TILE_SIZE 64

typedef struct s_keystate
{
	bool		up;
	bool		down;
	bool		left;
	bool		rigth;
}				t_keystate;

/* Game State Structure */
typedef struct s_game
{
	char **map; // 2D array of the map
	bool		g_key_pressed;
	int width;                     // Width of the map
	int height;                    // Height of the map
	int player_x;                  // Player's X position
	int player_y;                  // Player's Y position
	int collectibles;              // Number of collectibles
	int moves;                     // Number of moves
	bool game_completed;           // Game completion state
	mlx_t *mlx;                    // MLX42 instance
	mlx_texture_t *textures[4];    // Array of textures
	mlx_image_t *move_counter_img; // Move counter display
	t_keystate	key_state;
}				t_game;
typedef struct s_map_stats
{
	int			player_count;
	int			exit_count;
}				t_map_stats;

/* Flood-Fill State Structure */
typedef struct s_flood_fill
{
	bool **visited;    // 2D array to track visited positions
	int flooded_items; // Count of found collectibles
	bool exit_found;   // Whether the exit was found
}				t_flood_fill;
bool			validate_accessibility(t_game *game);
bool			is_valid_tile(t_game *game, int x, int y, t_flood_fill *state);

/* Global Variables */
extern bool keys_pressed[512]; // Tracks the state of pressed keys
// In so_long.h

bool			validate_map(t_game *game);
bool			flood_fill(t_game *game, int *flooded_items, bool *exit_found);

/* Function Prototypes */
char			*get_next_line(int fd);
/* Map Validation */
bool			validate_map(t_game *game);
void			count_collectibles(t_game *game);
bool			validate_borders(t_game *game);
bool			validate_elements(t_game *game, t_map_stats *stats);
bool			validate_row_lengths(t_game *game);

bool			initialize_game(t_game *game, const char *map_file);
void			handle_collectible_and_exit(t_game *game, int new_x, int new_y);
void			move_player(t_game *game, int dx, int dy);

/* Flood-Fill Utilities */
void			free_visited(bool **visited, int height);
bool			perform_flood_fill(t_game *game);

/* Rendering */
void			render_map(t_game *game);
void			update_move_counter(t_game *game);
void			render_tile(t_game *game, int x, int y);

/* Input Handling */
void			handle_input(t_game *game);
void			move_player(t_game *game, int dx, int dy);
void			handle_key_press(mlx_key_data_t keydata, void *param);
void			update_player_position(t_game *game);

/* Pixel Utility */
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

/* Map Loading */
bool			load_map(const char *filename, t_game *game);

#endif
