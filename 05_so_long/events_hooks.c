/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:26:33 by ngasco            #+#    #+#             */
/*   Updated: 2021/09/28 20:43:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_map *map)
{
	ft_put_str("So long!\n");
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

int	ft_keyboard_events(int keycode, t_map *map)
{
	printf("%d\n", keycode);
	if (keycode == 97 || keycode == 65361)
		ft_move_player(map, -1, 0);
	else if (keycode == 119 || keycode == 65362)
		ft_move_player(map, 0, -1);
	else if (keycode == 100 || keycode == 65363)
		ft_move_player(map, 1, 0);
	else if (keycode == 115 || keycode == 65364)
		ft_move_player(map, 0, 1);
	else if (keycode == 65307)
		ft_close_window(map);
	return (1);
}
int	ft_automated_events(t_map *map)
{
	int static i;
	
	if (!i)
		i = 0;
	if (i % 55555 == 0)
		ft_enemy_movement(map);
	i++;

}

void	ft_listen_events(t_map *map)
{
	mlx_hook(map->win, 02, (1L << 0), ft_keyboard_events, map);
	mlx_hook(map->win, 17, (1L << 8), ft_close_window, map);
	mlx_loop_hook(map->mlx, ft_automated_events, map);
}
