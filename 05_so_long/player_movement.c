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

void    ft_move_player(t_map *map, int x, int y)
{
	int	exit_flag;
	
	exit_flag = 0;
    if (map->map[map->p_y + y][map->p_x + x] != '1')
    {
		map->moves += 1;
		if (map->map[map->p_y + y][map->p_x + x] == '0')
		{
			// printf("Moving freely\n");
			ft_swap_tiles(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
		}
		else if (map->map[map->p_y + y][map->p_x + x] == 'C')
		{
			// printf("Found a collectible\n");
			ft_remove_collectible(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
			map->n_collect--;
		}
		else if (map->map[map->p_y + y][map->p_x + x] == 'E')
		{
			// printf("Found an exit\n");
			if (map->n_collect == 0)
			{
				ft_found_exit(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
				map->end_game = 1;
			}
			else
				ft_put_str("Collect all objects first.\n");
		}
		ft_put_str("Moves: ");
		ft_put_str(ft_itoa(map->moves));
		ft_put_str("\n");
    }
	ft_populate_map(map, 40, 0);
	if (map->end_game == 1)
	{
		ft_put_str("Well done, pirate!\nSo long...\n");
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}

}