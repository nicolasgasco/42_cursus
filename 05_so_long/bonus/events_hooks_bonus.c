/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:26:33 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/02 12:35:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_window(t_map *map)
{
	ft_end_game(map);
	return (1);
}

int	ft_key_event(t_map *map, int py, int px, int direction)
{
	ft_move_player(map, py, px);
	map->p_direction = direction;
	ft_populate_map(map, 40, 0);
	return (1);
}

int	ft_keyboard_events(int key, t_map *map)
{
	if (key == 65307 || key == 53)
		ft_close_window(map);
	if (map->p_death != 1 && map->end_game != 1)
	{
		if (key == 119 || key == 65362 || key == 13 || key == 126)
			ft_key_event(map, 0, -1, 0);
		else if (key == 100 || key == 65363 || key == 2 || key == 124)
			ft_key_event(map, 1, 0, 1);
		else if (key == 115 || key == 65364 || key == 1 || key == 125)
			ft_key_event(map, 0, 1, 2);
		else if (key == 97 || key == 65361 || key == 0 || key == 123)
			ft_key_event(map, -1, 0, 3);
	}
	else
		ft_close_window(map);
	return (1);
}

int	ft_automated_events(t_map *map)
{
	long static	i;

	if (!i)
		i = 0;
	if (i % 5555 == 0 && i > 5555 && map->p_death != 1 && map->end_game != 1)
		ft_enemy_movement(map);
	if (i == LONG_MAX)
		i = 0;
	i++;
	return (i);
}

void	ft_listen_events(t_map *map)
{
	mlx_hook(map->win, 02, (1L << 0), ft_keyboard_events, map);
	mlx_hook(map->win, 17, (1L << 8), ft_close_window, map);
	if (map->enem_n == 1 && map->n_cols > 10 && map->n_rows > 10)
	{
		mlx_loop_hook(map->mlx, ft_automated_events, map);
	}
}
