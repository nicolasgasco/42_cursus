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

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_move_forward(t_map *map, double angle, int increment)
{
	double	radians;
	double	v_increase;
	double	l_increase;

	radians = angle * (M_PI / 180);
	v_increase = increment * sin(radians);
	l_increase = increment * cos(radians);
	if (ft_forward_movement_hits_wall(map, v_increase, l_increase))
		return ;
	map->prj->player->y -= v_increase;
	map->prj->player->x += l_increase;
}

void	ft_move_backward(t_map *map, double angle, int increment)
{
	double	radians;
	double	v_increase;
	double	l_increase;

	radians = angle * (M_PI / 180);
	v_increase = increment * sin(radians);
	l_increase = increment * cos(radians);
	if (ft_backward_movement_hits_wall(map, v_increase, l_increase))
		return ;
	map->prj->player->y += v_increase;
	map->prj->player->x -= l_increase;
}

void	ft_move_leftward(t_map *map, double angle, int increment)
{
	double	new_angle;

	new_angle = angle - 90;
	if (new_angle < 0)
		new_angle = 360 + new_angle;
	ft_move_backward(map, new_angle, increment);
}

void	ft_move_rightward(t_map *map, double angle, int increment)
{
	double	new_angle;

	new_angle = angle - 90;
	if (new_angle < 0)
		new_angle = 360 + new_angle;
	ft_move_forward(map, new_angle, increment);
}
