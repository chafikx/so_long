/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:58:03 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/04/08 17:58:04 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}

int	close_game(t_game *game)
{
	ft_putstr_fd("Fermeture du jeu.\n", 1);
	free_map(game);
	if (game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx_ptr, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr); free(game->mlx_ptr);
	exit(0);
	return (0);
}
int	close_game(t_game *game)
{
	ft_putstr_fd("Fermeture du jeu.\n", 1);
	exit(0);
	return (0);
}

void	move_player(t_game *game, int new_y, int new_x)
{
	char	next_case;

	next_case = game->map[new_y][new_x];
	if (next_case == '1')
		return ;
	if (next_case == 'C')
	{
		game->c_count--;
		game->map[new_y][new_x] = '0';
	}
	if (next_case == 'E')
	{
		if (game->c_count == 0)
			close_game(game);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = new_y;
	game->player_x = new_x;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	printf("Mouvements : %d\n", game->moves);
	render_map(game);
}

int	key_input(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		close_game(game);
	else if (keycode == 13 || keycode == 119)
		move_player(game, game->player_y - 1, game->player_x);
	else if (keycode == 0 || keycode == 97)
		move_player(game, game->player_y, game->player_x - 1);
	else if (keycode == 1 || keycode == 115)
		move_player(game, game->player_y + 1, game->player_x);
	else if (keycode == 2 || keycode == 100)
		move_player(game, game->player_y, game->player_x + 1);
	return (0);
}