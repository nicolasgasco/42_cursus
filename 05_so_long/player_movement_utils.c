#include "so_long.h"

void    ft_swap_tiles(char *tile1, char *tile2)
{
	char	temp;

	// printf("Swapping tiles...\n");
	temp = *tile1;
	*tile1 = *tile2;
	*tile2 = temp;
}

void    ft_remove_collectible(char *player, char *collect)
{
	char	temp;

	// printf("Taking collectible...\n");
	*collect = *player;
	*player = '0';
}

void    ft_found_exit(char *player, char *collect)
{
	char	temp;

	// printf("Found exit...\n");
	*collect = *player;
	*player = '0';
}

void    ft_end_game(t_map *map)
{
	if (map->end_game == 1)
	{
		ft_put_str("Well done, pirate!\nSo long...\n");
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
}

void	ft_print_map(char **map)
{
	int x = 0;
	int y = 0;
	while (map[y] != NULL)
	{
		printf("%s\n", map[y]);
		y++;
	}
}