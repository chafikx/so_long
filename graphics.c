#include "so_long.h"

void	init_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_putstr_fd("Error\nÉchec de la connexion MLX\n", 2);
		exit(EXIT_FAILURE);
	}
	int window_width = game->map_width * TILE_SIZE;
	int window_height = game->map_height * TILE_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_width, window_height, "so_long");
	if (!game->win_ptr)
	{
		ft_putstr_fd("Error\nImpossible d'ouvrir la fenêtre\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm", &width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "assets/player.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx_ptr, "assets/collect.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm", &width, &height);
	if (!game->img_wall || !game->img_floor || !game->img_player 
		|| !game->img_collect || !game->img_exit)
	{
		ft_putstr_fd("Error\nImpossible de charger les textures XPM\n", 2);
		exit(EXIT_FAILURE);
	}
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
			if (game->map[y][x] != '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_collect, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}