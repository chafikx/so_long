#include "so_long.h"
#include <fcntl.h>

int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nImpossible d'ouvrir le fichier\n", 2);
		exit(EXIT_FAILURE);
	}
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

char	**read_map(char *filename)
{
	int		fd;
	int		height;
	int		i;
	char	**map;

	height = get_map_height(filename);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	check_map_elements(t_game *game)
{
	int	y;
	int	x;
	int	p_count = 0;
	int	e_count = 0;

	game->c_count = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
				p_count++;
			else if (game->map[y][x] == 'E')
				e_count++;
			else if (game->map[y][x] == 'C')
				game->c_count++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				return (0);
		}
	}
	if (p_count != 1 || e_count != 1 || game->c_count < 1)
		return (0);
	return (1);
}

void	flood_fill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}

char	**duplicate_map(char **original_map, int height)
{
	char	**clone;
	int		i;

	clone = malloc(sizeof(char *) * (height + 1));
	if (!clone)
		return (NULL);
	
	i = 0;
	while (i < height)
	{
		clone[i] = ft_strdup(original_map[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}