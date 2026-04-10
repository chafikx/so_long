/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:57:57 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/04/10 16:52:39 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid extension\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	validate_all(t_game *game)
{
	if (!check_map_elements(game))
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_valid_path(game))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <map.ber>\n", 2);
		return (1);
	}
	check_extension(argv[1]);
	game.moves = 0;
	game.map_height = get_map_height(argv[1]);
	game.map = read_map(argv[1]);
	if (!game.map || !validate_all(&game))
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		free_matrix(game.map);
		return (1);
	}
	init_graphics(&game);
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_input, &game);
	mlx_hook(game.win_ptr, 17, 1L << 2, close_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
