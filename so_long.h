/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:37:52 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/04/10 16:41:34 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define TILE_SIZE 64

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		c_count;
	int		moves;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_game;

int		get_map_height(char *filename);
char	**read_map(char *filename);
void	flood_fill(char **map_copy, int x, int y);
char	**duplicate_map(char **original_map, int height);
void	free_matrix(char **matrix);

int		check_map_elements(t_game *game);
int		check_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_valid_path(t_game *game);

void	init_graphics(t_game *game);
void	load_images(t_game *game);
void	put_sprite(t_game *game, int x, int y);
int		render_map(t_game *game);

int		key_input(int keycode, t_game *game);
int		close_game(t_game *game);

void	check_extension(char *filename);
int		validate_all(t_game *game);

#endif