/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_tiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:27:49 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:35:38 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_rocks(t_map *map, int offset, int index)
{
	if ((index + 1) % 5 == 0)
		ft_render_tile(map, "./img/rock_3.xpm", offset);
	else if ((index + 1) % 3 == 0)
		ft_render_tile(map, "./img/rock_2.xpm", offset);
	else
		ft_render_tile(map, "./img/rock_1.xpm", offset);
}


void	ft_render_player(t_map *map, int offset, int x, int y)
{
	if (map->end_game == 1)
		ft_render_tile(map, "./img/success.xpm", offset);
	else if (map->p_death == 1)
		ft_render_tile(map, "./img/dead.xpm", offset);
	else if (map->found_collect == 1)
	{
		if (map->x % 2 == 0)
			ft_render_tile(map, "./img/yoda_egg.xpm", offset);
		else if (map->x % 2 != 0)
			ft_render_tile(map, "./img/yoda_star.xpm", offset);
	}
	else
	{	
		if (map->p_direction == 0)
			ft_render_tile(map, "./img/player_up.xpm", offset);
		else if (map->p_direction == 1)
			ft_render_tile(map, "./img/player_right.xpm", offset);
		else if (map->p_direction == 2)
			ft_render_tile(map, "./img/player.xpm", offset);
		else if (map->p_direction == 3)
			ft_render_tile(map, "./img/player_left.xpm", offset);
	}
	map->p_x = x;
	map->p_y = y;
}

void	ft_render_exit(t_map *map, int offset, int start)
{
	if (start == 0 && map->n_collect == 0)
		ft_render_tile(map, "./img/exit.xpm", offset);
	else
		ft_render_tile(map, "./img/exit_closed.xpm", offset);
}

void	ft_render_collectible(t_map *map, int offset, int start)
{
	if (start == 1)
		map->n_collect += 1;
	if (map->x % 2 == 0)
		ft_render_tile(map, "./img/egg_1.xpm", offset);
	else if (map->x % 2 != 0)
		ft_render_tile(map, "./img/star.xpm", offset);
}

void	ft_render_enemy(t_map *map, int offset, int x, int y)
{
	ft_render_tile(map, "./img/enemy.xpm", offset);
	map->e_x = x;
	map->e_y = y;
	map->enem_n += 1;
}
