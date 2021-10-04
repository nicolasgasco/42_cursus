/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:11 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/04 19:14:42 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_end_game(t_map *map)
{
	ft_put_str("So long, child...\n");
	mlx_destroy_window(map->mlx, map->win);
	free(map->map);
	free(map->b_tile);
	exit(0);
}

void	ft_moved_into_collect(t_map *map, int x, int y)
{
	int	p_y;
	int	p_x;

	p_x = map->p_x;
	p_y = map->p_y;
	ft_remove_collect(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
	ft_put_str("You collected an object!\n");
	map->n_collect -= 1;
	map->found_collect = 1;
}

void	ft_moved_into_exit(t_map *map, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	if (map->n_collect == 0)
	{
		ft_found_exit(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		map->end_game = 1;
		ft_put_str("You found an exit!\n");
		ft_put_str("Press any key to exit.\n");
	}
	else
		ft_put_str("Collect all objects first.\n");
}

void	ft_put_enemy_message(void)
{
	ft_put_str("You stepped into an enemy!\n");
	ft_put_str("Press any key to exit.\n");
}

void	ft_move_player(t_map *map, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	ft_check_if_end(map);
	map->found_collect = 0;
	if (map->map[p_y + y][p_x + x] != '1')
	{
		map->moves += 1;
		if (map->map[p_y + y][p_x + x] == '0')
			ft_swap_tiles(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		else if (map->map[p_y + y][p_x + x] == 'C')
			ft_moved_into_collect(map, x, y);
		else if (map->map[p_y + y][p_x + x] == 'E')
			ft_moved_into_exit(map, x, y);
		else if (map->map[p_y + y][p_x + x] == 'M')
		{
			ft_remove_collect(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
			ft_put_enemy_message();
			map->p_death = 1;
		}
		ft_render_ui(map, 40);
		ft_populate_map(map, 40, 0);
	}
}
