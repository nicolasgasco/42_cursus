/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:40:48 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/19 11:21:51 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include <math.h>

/* ft_horizontal_increment pre-calculates the increment the ray will follow 
 * depending on the angle of the ray.*/

t_vector	ft_horizontal_increment(int texture_size, int angle)
{
	static t_vector	horizontal_increment[360 * WIN_WIDTH / FIELD_OF_VIEW];
	int				i;

	if (horizontal_increment[0].x > 0 || horizontal_increment[0].y > 0)
		return (horizontal_increment[angle]);
	i = 0;
	while (i < ft_transform_angle(360))
	{
		if (ft_is_facing_down(i) == 0)
			horizontal_increment[i].y = texture_size * -1;
		else
			horizontal_increment[i].y = texture_size;
		horizontal_increment[i].x = fabs(texture_size / ft_tangent(i));
		if (ft_is_facing_right(i) == 0)
			horizontal_increment[i].x *= -1;
		i++;
	}
	return (horizontal_increment[angle]);
}

/* ft_vertical_increment pre-calculates the increment the ray will follow 
 * depending on the angle of the ray.*/

t_vector	ft_vertical_increment(int texture_size, int angle)
{
	static t_vector	vertical_increment[360 * WIN_WIDTH / FIELD_OF_VIEW];
	int				i;

	if (vertical_increment[0].x > 0 || vertical_increment[0].y > 0)
		return (vertical_increment[angle]);
	i = 0;
	while (i < ft_transform_angle(360))
	{
		if (ft_is_facing_right(i) == 0)
			vertical_increment[i].x = texture_size * -1;
		else
			vertical_increment[i].x = texture_size;
		vertical_increment[i].y = fabs(texture_size * ft_tangent(i));
		if (ft_is_facing_down(i) == 0)
			vertical_increment[i].y *= -1;
		i++;
	}
	return (vertical_increment[angle]);
}
