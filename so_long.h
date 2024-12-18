/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jretter <jretter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:39:39 by jretter           #+#    #+#             */
/*   Updated: 2024/12/18 18:11:16 by jretter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* ************************************************************************** */
/*                                 CONSTANTS                                  */
/* ************************************************************************** */

# define TILE_SIZE 64

/* ************************************************************************** */
/*                                  STRUCTURES                                */
/* ************************************************************************** */

typedef struct s_game
{
	char			**map;
	bool			g_key_pressed;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				collectibles;
	int				moves;
	bool			game_completed;
	mlx_t			*mlx;
	mlx_texture_t	*textures[4];
	mlx_image_t		*move_counter_img;
}					t_game;

typedef struct s_map_stats
{
	int				player_count;
	int				exit_count;
}					t_map_stats;

typedef struct s_flood_fill
{
	bool			**visited;
	int				flooded_items;
	bool			exit_found;
}					t_flood_fill;

/* ************************************************************************** */
/*                              FUNCTION PROTOTYPES                           */
/* ************************************************************************** */

bool				validate_map(t_game *game);
bool				validate_borders(t_game *game);
bool				validate_elements(t_game *game, t_map_stats *stats);
bool				validate_row_lengths(t_game *game);
void				count_collectibles(t_game *game);

bool				initialize_game(t_game *game, const char *map_file);

bool				perform_flood_fill(t_game *game);
bool				is_valid_tile(t_game *game, int x, int y,
						t_flood_fill *state);
void				free_visited(bool **visited, int height);

void				render_map(t_game *game);
void				update_move_counter(t_game *game);
void				render_tile(t_game *game, int x, int y);

void				handle_input(t_game *game);
void				move_player(t_game *game, int dx, int dy);
void				handle_key_press(mlx_key_data_t keydata, void *param);
void				update_player_position(t_game *game);
void				cleanup_game(t_game *game);

int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

/* Map Loading */
bool				load_map(const char *filename, t_game *game);
void				render_player(t_game *game);

/* ************************************************************************** */
/*                                  UTILITIES                                 */
/* ************************************************************************** */

char				*get_next_line(int fd);

#endif
