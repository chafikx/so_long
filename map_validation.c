/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:37:28 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/04/08 18:37:31 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_and_check(t_game *game, int *p, int *e, int y)
{
	int	x;

	x = 0;
	while (game->map[y][x])
	{
		if (game->map[y][x] == 'P')
		{
			(*p)++;
			game->player_x = x;
			game->player_y = y;
		}
		else if (game->map[y][x] == 'E')
			(*e)++;
		else if (game->map[y][x] == 'C')
			game->c_count++;
		else if (game->map[y][x] != '0' && game->map[y][x] != '1'
			&& game->map[y][x] != '\n')
			return (0);
		x++;
	}
	return (1);
}

int	check_map_elements(t_game *game)
{
	int	y;
	int	p;
	int	e;

	p = 0;
	e = 0;
	game->c_count = 0;
	y = 0;
	while (game->map[y])
	{
		if (!count_and_check(game, &p, &e, y))
			return (0);
		y++;
	}
	if (p != 1 || e != 1 || game->c_count < 1)
		return (0);
	return (1);
}

int	check_rectangular(t_game *game)
{
	int	y;
	int	x;

	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
			x++;
		if (x != game->map_width)
			return (0);
		y++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	if (!check_rectangular(game))
		return (0);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (y == 0 || y == game->map_height - 1
				|| x == 0 || x == game->map_width - 1)
			{
				if (game->map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_valid_path(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;
	int		valid;

	valid = 1;
	map_copy = duplicate_map(game->map, game->map_height);
	flood_fill(map_copy, game->player_x, game->player_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				valid = 0;
			x++;
		}
		y++;
	}
	free_matrix(map_copy);
	return (valid);
}
