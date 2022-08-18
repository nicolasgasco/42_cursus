/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_desc_file_validation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/06/09 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

int	ft_rgb_str_to_int(char *col_str)
{
	int	*rgb;
	int	int_result;

	rgb = (int *)malloc(sizeof(int) * 3);
	ft_populate_rgb_int_arr(col_str, rgb);
	int_result = ft_rgb_to_int(NO_TRANSPARENCY, rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (int_result);
}

void	ft_populate_rgb_int_arr(char *col_str, int *rgb)
{
	int	i;
	int	comma_i;
	int	rgb_counter;

	i = 0;
	comma_i = 0;
	rgb_counter = 0;
	while (col_str[i] != '\0')
	{
		if (col_str[i] == ',')
		{
			rgb[rgb_counter] = ft_substr_and_atoi(col_str, comma_i, i);
			rgb_counter++;
			comma_i = i + 1;
		}
		i++;
	}
	rgb[rgb_counter] = ft_substr_and_atoi(col_str, comma_i, i);
}

int	ft_substr_and_atoi(char *col_str, int start, int end)
{
	char	*single_col_str;
	int		int_col;

	single_col_str = ft_substr(col_str, start, end - start);
	int_col = ft_atoi(single_col_str);
	free(single_col_str);
	return (int_col);
}

int	ft_rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
