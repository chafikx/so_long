#include "so_long.h"

void	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nLa carte doit avoir l'extension .ber\n", 2);
		exit(EXIT_FAILURE);
	}
}


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <map.ber>\n", 2);
		return (1);
	}
	check_extension(argv[1]);
	
	// La suite ici
	
	return (0);
}