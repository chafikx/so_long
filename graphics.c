/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:37:40 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/04/08 18:38:25 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(EXIT_FAILURE);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		exit(EXIT_FAILURE);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/player.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/collect.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/exit.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collect || !game->img_exit)
		exit(EXIT_FAILURE);
}

void	put_sprite(t_game *game, int x, int y)
{
	if (game->map[y][x] != '1' && game->map[y][x] != '\n')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_floor, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_wall, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_collect, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_exit, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_player, x * 64, y * 64);
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_sprite(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
