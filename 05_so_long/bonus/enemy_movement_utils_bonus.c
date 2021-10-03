/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:11 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:36:01 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_kill_player(t_map *map, char *enemy)
{
	*enemy = '0';
	map->p_death = 1;
	ft_populate_map(map, 40, 0);
	ft_put_str("The enemy was faster than you!\n");
	ft_put_str("Press any key to exit.\n");
}

void	ft_enemy_up(t_map *map, int *x, int *y, int *direction)
{
	if (map->map[*y - 1][*x + 1] == '0')
	{
		ft_swap_tiles(&map->map[*y][*x], &map->map[*y - 1][*x + 1]);
		*y -= 1;
		*x += 1;
	}
	else if (map->map[*y - 1][*x + 1] == 'P')
		ft_kill_player(map, &map->map[*y][*x]);
	else
		*direction += 1;
}

void	ft_enemy_right(t_map *map, int *x, int *y, int *direction)
{
	if (map->map[*y + 1][*x + 1] == '0')
	{
		ft_swap_tiles(&map->map[*y][*x], &map->map[*y + 1][*x + 1]);
		*y += 1;
		*x += 1;
	}
	else if (map->map[*y + 1][*x + 1] == 'P')
		ft_kill_player(map, &map->map[*y][*x]);
	else
		*direction += 1;
}

void	ft_enemy_down(t_map *map, int *x, int *y, int *direction)
{
	if (map->map[*y + 1][*x - 1] == '0')
	{
		ft_swap_tiles(&map->map[*y][*x], &map->map[*y + 1][*x - 1]);
		*y += 1;
		*x -= 1;
	}
	else if (map->map[*y + 1][*x - 1] == 'P')
		ft_kill_player(map, &map->map[*y][*x]);
	else
		*direction += 1;
}

void	ft_enemy_left(t_map *map, int *x, int *y, int *direction)
{
	if (map->map[*y - 1][*x - 1] == '0')
	{
		ft_swap_tiles(&map->map[*y][*x], &map->map[*y - 1][*x - 1]);
		*y -= 1;
		*x -= 1;
	}
	else if (map->map[*y - 1][*x - 1] == 'P')
		ft_kill_player(map, &map->map[*y][*x]);
	else
	{
		*direction = 0;
		*y -= 1;
		*x -= 1;
	}
}
