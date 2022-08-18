/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_calculation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:56:57 by jsolinis          #+#    #+#             */
/*   Updated: 2022/08/07 20:30:03 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"
#include <math.h>

/*ft_horizontal_intersection will find the hit(s) with the
 * horizontal axis of the map until there is a wall*/

double	ft_horizontal_intersection(t_map *map, int current_angle)
{
	t_vector	intersection;
	t_vector	increment;

	intersection.y = floor(map->prj->player->y / map->texture_size)
		* map->texture_size;
	if (ft_is_facing_down(current_angle) == 0)
		intersection.y -= 1;
	else
		intersection.y += map->texture_size;
	intersection.x = map->prj->player->x
		+ (map->prj->player->y - intersection.y) / ft_tangent(current_angle);
	increment = ft_horizontal_increment(map->texture_size, current_angle);
	while (ft_hit(map, intersection, current_angle) == 0)
		intersection = ft_increment(intersection, increment);
	if (intersection.y < 0 || intersection.x < 0
		|| intersection.y / map->texture_size > map->height
		|| intersection.x / map->texture_size > map->width)
		return (2147483647);
	map->slc->h_wall_x = (int)(intersection.x) % map->texture_size;
	return (fabs(fabs(map->prj->player->y - intersection.y)
			/ ft_sine(current_angle)));
}

/*ft_vertical_intersection will find the hit(s) with the
 * vertical axis of the map until there is a wall*/

double	ft_vertical_intersection(t_map *map, int current_angle)
{
	t_vector	intersection;
	t_vector	increment;

	intersection.x = floor(map->prj->player->x / map->texture_size)
		* map->texture_size;
	if (ft_is_facing_right(current_angle) == 0)
		intersection.x -= 1;
	else
		intersection.x += map->texture_size;
	intersection.y = map->prj->player->y
		+ (map->prj->player->x - intersection.x) * ft_tangent(current_angle);
	increment = ft_vertical_increment(map->texture_size, current_angle);
	while (ft_hit(map, intersection, current_angle) == 0)
		intersection = ft_increment(intersection, increment);
	if (intersection.y < 0 || intersection.x < 0
		|| intersection.y / map->texture_size > map->height
		|| intersection.x / map->texture_size > map->width)
		return (2147483647);
	map->slc->v_wall_x = (int)(intersection.y) % map->texture_size;
	return (fabs(fabs(map->prj->player->x - intersection.x)
			/ ft_cosine(current_angle)));
}

/*ft_calculate_distance will calculate the distances from 
 * the player to the horizontal & vertical intersections.*/

double	ft_calculate_distance(t_map *map)
{
	int		current_angle;
	double	distance_horizontal;
	double	distance_vertical;

	current_angle = ft_transform_angle(map->prj->view_angle) + map->slc->angle;
	if (current_angle < 0)
		current_angle += ft_transform_angle(360);
	if (current_angle >= ft_transform_angle(360))
		current_angle -= ft_transform_angle(360);
	distance_horizontal = ft_horizontal_intersection(map, current_angle);
	distance_vertical = ft_vertical_intersection(map, current_angle);
	if (distance_horizontal < distance_vertical)
	{
		map->slc->wall_x = map->slc->h_wall_x;
		ft_get_texture(map, current_angle, 'H');
		return (distance_horizontal);
	}
	else
	{
		map->slc->wall_x = map->slc->v_wall_x;
		ft_get_texture(map, current_angle, 'V');
		return (distance_vertical);
	}
}

/*ft_raycasting_calculation initializes the loop to
 * calculate & render the rays or slices.*/

void	ft_raycasting_calculation(t_map *map)
{	
	t_slice	*slc;

	slc = malloc (sizeof(t_slice));
	ft_memset(slc, 0, sizeof(t_slice));
	map->slc = slc;
	ft_convert_to_cube_position(map);
	map->slc->angle = ft_transform_angle(30);
	while (map->slc->angle > (ft_transform_angle(30) * -1)
		&& map->slc->column < WIN_WIDTH)
	{
		map->slc->distance_to_wall = ft_calculate_distance(map);
		map->slc->height = map->slc->distance_to_wall
			* ft_cosine(abs(map->slc->angle));
		map->slc->height = (((double)(map->texture_size))
				/ map->slc->height) * map->prj->distance_to_pp;
		ft_render_raycasting_column(map);
		map->slc->column++;
		map->slc->angle--;
	}
	mlx_put_image_to_window(map->view->mlx, map->view->mlx_win,
		map->view->plane_data->img, 0, 0);
	free(map->slc);
}
