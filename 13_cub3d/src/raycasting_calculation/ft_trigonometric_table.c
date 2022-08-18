/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigonometric_table.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:24:57 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/19 11:27:20 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

/* ft_sine is a pre-calculated table with all possible angles */

double	ft_cosine(int angle)
{
	static double	cosine[360 * WIN_WIDTH / FIELD_OF_VIEW];
	int				i;

	if (angle < 0 || angle >= ft_transform_angle(360))
		return (0.0);
	if (cosine[ft_transform_angle(0)] > 1.0)
		return (cosine[angle]);
	i = 0;
	while (i < ft_transform_angle(360))
	{
		cosine[i] = cos(i * PI / ft_transform_angle(180)) + 0.00001;
		i++;
	}
	return (cosine[angle]);
}

/* ft_sine is a pre-calculated table with all possible angles */

double	ft_sine(int angle)
{
	static double	sine[360 * WIN_WIDTH / FIELD_OF_VIEW];
	int				i;

	if (angle < 0 || angle >= ft_transform_angle(360))
		return (0.0);
	if (sine[ft_transform_angle(90)] > 1.0)
		return (sine[angle]);
	i = 0;
	while (i < ft_transform_angle(360))
	{
		sine[i] = sin(i * PI / ft_transform_angle(180)) + 0.00001;
		i++;
	}
	return (sine[angle]);
}

/* ft_tangent is a pre-calculated table with all possible angles */

double	ft_tangent(int angle)
{
	static double	tangent[360 * WIN_WIDTH / FIELD_OF_VIEW];
	int				i;

	if (angle < 0 || angle >= ft_transform_angle(360))
		return (0.0);
	if (tangent[ft_transform_angle(45)] > 1.0)
		return (tangent[angle]);
	i = 0;
	while (i < ft_transform_angle(360))
	{
		tangent[i] = tan(i * PI / ft_transform_angle(180)) + 0.00001;
		i++;
	}
	return (tangent[angle]);
}
