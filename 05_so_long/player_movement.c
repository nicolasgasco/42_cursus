#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_put_moves(t_map *map)
{		
		ft_put_str("Moves: ");
		ft_putnbr_fd(map->moves, 1);
		ft_put_str("\n");
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
			ft_swap_tiles(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
		}
		else if (map->map[map->p_y + y][map->p_x + x] == 'C')
		{
			ft_remove_collectible(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
			map->n_collect--;
		}
		else if (map->map[map->p_y + y][map->p_x + x] == 'E')
		{
			if (map->n_collect == 0)
			{
				ft_found_exit(&map->map[map->p_y][map->p_x], &map->map[map->p_y + y][map->p_x + x]);
				map->end_game = 1;
			}
			else
				ft_put_str("Collect all objects first.\n");
		}
		ft_put_moves(map);
		ft_populate_map(map, 40, 0);
	}
	ft_end_game(map);
}