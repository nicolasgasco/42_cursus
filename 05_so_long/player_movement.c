#include "so_long.h"

// void    ft_update_tile(t_map *map, char *path, int offset)
// {
//     t_img     tile;
//     void    *rendered_tile;
//     int     width;
//     int     height;

//     tile.width = 32;
//     tile.height = 32;
//     rendered_tile = mlx_xpm_file_to_image(map->mlx, path, &tile.width, &tile.height);
//     mlx_put_image_to_window (map->mlx, map->win, rendered_tile, map->x * 32 + offset, map->y * 32 + offset);
// }

void    ft_swap_tiles(char *tile1, char *tile2)
{
	char	temp;

	printf("Swapping tiles...\n");
	temp = *tile1;
	*tile1 = *tile2;
	*tile2 = temp;
}

void    ft_remove_collectible(char *player, char *collect)
{
	char	temp;

	printf("Taking collectible...\n");
	*collect = *player;
	*player = '0';
}

void    ft_found_exit(char *player, char *collect)
{
	char	temp;

	printf("Found exit...\n");
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
			printf("Moving freely\n");
			ft_swap_tiles(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
		}
		else if (map->map[map->p_y + y][map->p_x + x] == 'C')
		{
			printf("Found a collectible\n");
			ft_remove_collectible(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
		}
		else if (map->map[map->p_y + y][map->p_x + x] == 'E')
		{
			printf("Found an exit\n");
			ft_found_exit(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
			map->end_game = 1;
		}
		printf("Moves: %d\n", map->moves);
    }
	ft_populate_map(map, 40);
	if (map->end_game == 1)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}

}