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
	static int	direction;
	int			x;
	int			y;

	x = map->e_x;
	y = map->e_y;
	if (!direction)
		direction = 0;
	if (direction == 0)
		ft_enemy_up(map, &x, &y, &direction);
	if (direction == 1)
		ft_enemy_right(map, &x, &y, &direction);
	if (direction == 2)
		ft_enemy_down(map, &x, &y, &direction);
	if (direction == 3)
		ft_enemy_left(map, &x, &y, &direction);
	ft_populate_map(map, 40, 0);
}