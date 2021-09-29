/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:11 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/28 20:40:47 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_kill_player(t_map *map, char *enemy)
{
	*enemy = '0';
	map->p_death = 1;
	ft_populate_map(map, 40, 0);
	ft_check_if_end(map);
}

void    ft_enemy_movement(t_map *map)
{
	static int	direction;
	int			x;
	int			y;

	x = map->e_x;
	y = map->e_y;
	if (!direction)
		direction = 0;
	if (direction == 0)
	{
		ft_check_if_end(map);
		if (map->map[y - 1][x + 1] == '0')
		{
			ft_swap_tiles(&map->map[y][x], &map->map[y - 1][x + 1]);
			y--;
			x++;
		}
		else if (map->map[y - 1][x + 1] == 'P')
		{
			ft_kill_player(map, &map->map[y][x]);
		}
		else
			direction++;
	}
	if (direction == 1)
	{
		if (map->map[y + 1][x + 1] == '0')
		{
			ft_swap_tiles(&map->map[y][x], &map->map[y + 1][x + 1]);
			y++;
			x++;
		}
		else if (map->map[y + 1][x + 1] == 'P')
		{
			ft_kill_player(map, &map->map[y][x]);
		}
		else
			direction++;
	}
	if (direction == 2)
	{
		if (map->map[y + 1][x - 1] == '0')
		{
			ft_swap_tiles(&map->map[y][x], &map->map[y + 1][x - 1]);
			y++;
			x--;
		}
		else if (map->map[y + 1][x - 1] == 'P')
		{
			ft_kill_player(map, &map->map[y][x]);
		}
		else
			direction++;
	}
	if (direction == 3)
	{
		if (map->map[y - 1][x - 1] == '0')
		{
			ft_swap_tiles(&map->map[y][x], &map->map[y - 1][x - 1]);
			y--;
			x--;
		}
		else if (map->map[y - 1][x - 1] == 'P')
		{
			ft_kill_player(map, &map->map[y][x]);
		}
		else
		{
			direction = 0;
			y--;
			x++;
		}
	}
	ft_populate_map(map, 40, 0);
}