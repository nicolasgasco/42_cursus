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

void    ft_enemy_movement(t_map *map)
{
    static int direction;

    if (!direction)
        direction = 0;
    if (direction == 0)
    {
        if (map->map[map->e_y - 1][map->e_x + 1] == '0')
        {
            ft_swap_tiles(&map->map[map->e_y][map->e_x], &map->map[map->e_y - 1][map->e_x + 1]);
            map->e_y--;
            map->e_x++;
        }
        else
            direction++;
    }
    if (direction == 1)
    {
        if (map->map[map->e_y + 1][map->e_x + 1] == '0')
        {
            ft_swap_tiles(&map->map[map->e_y][map->e_x], &map->map[map->e_y + 1][map->e_x + 1]);
            map->e_y++;
            map->e_x++;
        }
        else
            direction++;
    }
    if (direction == 2)
    {
        if (map->map[map->e_y + 1][map->e_x - 1] == '0')
        {
            ft_swap_tiles(&map->map[map->e_y][map->e_x], &map->map[map->e_y + 1][map->e_x - 1]);
            map->e_y++;
            map->e_x--;
        }
        else
            direction++;
    }
    if (direction == 3)
    {
        if (map->map[map->e_y - 1][map->e_x - 1] == '0')
        {
            ft_swap_tiles(&map->map[map->e_y][map->e_x], &map->map[map->e_y - 1][map->e_x - 1]);
            map->e_y--;
            map->e_x--;
        }
        else
        {
            direction = 0;
            ft_swap_tiles(&map->map[map->e_y][map->e_x], &map->map[map->e_y - 1][map->e_x + 1]);
            map->e_y--;
            map->e_x++;
        }
    }
    ft_populate_map(map, 40, 0);
}