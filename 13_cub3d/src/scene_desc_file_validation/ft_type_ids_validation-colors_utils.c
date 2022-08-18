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

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_check_col_already_assigned(t_map *map, char *color_id, char *line)
{
	if (ft_strncmp(color_id, "F", 1) == 0)
	{
		free(color_id);
		if (map->f_color)
		{
			free(line);
			ft_duplicate_scene_info_error_exit(map);
		}
	}
	else if (ft_strncmp(color_id, "C", 1) == 0)
	{
		free(color_id);
		if (map->c_color)
		{
			free(line);
			ft_duplicate_scene_info_error_exit(map);
		}
	}
}

int	ft_check_if_other_num_same_line(char *line, int iterator)
{
	int	i;

	i = iterator;
	while (line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}
