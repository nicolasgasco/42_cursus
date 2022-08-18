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

void	ft_render_game_scene(t_map *map)
{
	if (map->view->plane_data->img)
		mlx_destroy_image(map->view->mlx, map->view->plane_data->img);
	map->view->plane_data->img = mlx_new_image(map->view->mlx,
			WIN_WIDTH + 1, WIN_HEIGHT + 1);
	ft_raycasting_calculation(map);
}

void	ft_render_raycasting_column(t_map *map)
{
	t_data	*plane;

	plane = map->view->plane_data;
	plane->addr = mlx_get_data_addr(plane->img, &plane->bits_per_pixel,
			&plane->line_length, &plane->endian);
	map->y = 0;
	ft_render_ceiling(map, &map->y);
	ft_render_scaled_texture(map);
	ft_render_floor(map, &map->y);
}

void	ft_render_ceiling(t_map *map, int *y)
{
	int	offset;

	offset = (WIN_HEIGHT - map->slc->height) / 2;
	while (*y < offset)
	{
		ft_mlx_pixel_put(map->view->plane_data, map->slc->column,
			*y, map->rdata->c_col_int);
		*y += 1;
	}
}

void	ft_render_floor(t_map *map, int *y)
{
	while (*y < WIN_HEIGHT)
	{
		ft_mlx_pixel_put(map->view->plane_data, map->slc->column,
			*y, map->rdata->f_col_int);
		*y += 1;
	}
}
