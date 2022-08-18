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

int	ft_mouse_events(int x, int y, t_map *map)
{
	ft_mouse_rotation(x, y, map);
	ft_render_game_scene(map);
	return (0);
}

void	ft_mouse_rotation(int x, int y, t_map *map)
{
	int	win_quarter;
	int	win_eighth;
	int	increment;

	win_quarter = WIN_WIDTH / 4;
	win_eighth = WIN_WIDTH / 8;
	increment = 2;
	if (x <= win_quarter && y)
	{
		if (x <= win_eighth)
			increment = 4;
		ft_rotate_leftward(map, map->prj->view_angle, increment);
	}
	else if (x >= (WIN_WIDTH - win_quarter))
	{
		if (x >= (WIN_WIDTH - win_eighth))
			increment = 4;
		ft_rotate_rightward(map, map->prj->view_angle, increment);
	}
}
