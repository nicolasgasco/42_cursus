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

void	ft_rotate_leftward(t_map *map, double angle, int increment)
{
	int	new_angle;

	new_angle = ((int)angle + increment) % 360;
	map->prj->view_angle = new_angle;
}

void	ft_rotate_rightward(t_map *map, double angle, int increment)
{
	int	new_angle;
	int	current_angle;

	current_angle = (int)angle;
	if (current_angle <= 0)
		current_angle = 360;
	new_angle = current_angle - increment;
	map->prj->view_angle = new_angle;
}
