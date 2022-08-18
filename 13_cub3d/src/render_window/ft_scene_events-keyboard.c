/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/07/19 13:35:50 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

int	ft_keyboard_events(int key, t_map *map)
{
	if (key == ESC_KEY_LINUX || key == ESC_KEY_MAC)
		ft_close_window(map);
	else if (key == W_KEY_LINUX || key == W_KEY_MAC)
		ft_move_forward(map, map->prj->view_angle, V_MOVEMENT_INCREMENT);
	else if (key == S_KEY_LINUX || key == S_KEY_MAC)
		ft_move_backward(map, map->prj->view_angle, V_MOVEMENT_INCREMENT);
	else if (key == A_KEY_LINUX || key == A_KEY_MAC)
		ft_move_leftward(map, map->prj->view_angle, H_MOVEMENT_INCREMENT);
	else if (key == D_KEY_LINUX || key == D_KEY_MAC)
		ft_move_rightward(map, map->prj->view_angle, H_MOVEMENT_INCREMENT);
	else if (key == LEFT_ARR_LINUX || key == LEFT_ARR_MAC)
		ft_rotate_leftward(map, map->prj->view_angle, L_MOVEMENT_INCREMENT);
	else if (key == RIGHT_ARR_LINUX || key == RIGHT_ARR_MAC)
		ft_rotate_rightward(map, map->prj->view_angle, L_MOVEMENT_INCREMENT);
	ft_render_game_scene(map);
	return (1);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->view->mlx, map->view->mlx_win);
	ft_free_allocated_map_data(map);
	ft_free_raycast_data(map);
	exit (0);
}
