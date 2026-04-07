/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbenhiz <chbenhiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:52:33 by chbenhiz          #+#    #+#             */
/*   Updated: 2026/04/06 22:23:05 by chbenhiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_game
{
    char    **map;
    int map_width;
    int map_height;
    int player_x;
    int player_y;
    int c_count;
    int moves;
    void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
} t_game;