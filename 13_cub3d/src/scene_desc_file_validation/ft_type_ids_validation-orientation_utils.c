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

int	ft_calc_path_length(char *line, int i)
{
	int	len;

	len = 0;
	while (ft_isspace(line[i]) == 0 && line[i])
	{
		len++;
		i++;
	}
	return (len);
}

int	ft_check_o_path_already_assigned(t_map *map, char *o_path_id)
{
	if (ft_strncmp(o_path_id, "NO", 2) == 0)
	{
		if (map->no_path)
			return (1);
	}
	else if (ft_strncmp(o_path_id, "SO", 2) == 0)
	{
		if (map->so_path)
			return (1);
	}
	else if (ft_strncmp(o_path_id, "WE", 2) == 0)
	{
		if (map->we_path)
			return (1);
	}
	else if (ft_strncmp(o_path_id, "EA", 2) == 0)
	{
		if (map->ea_path)
			return (1);
	}
	return (0);
}

int	ft_validate_f_path(t_map *map, char *o_path, char *line, char *o_path_id)
{
	int	file_fd;

	file_fd = open(o_path, O_RDONLY);
	if (file_fd == -1)
	{
		ft_free_allocated_map_data(map);
		free(o_path);
		free(line);
		free(o_path_id);
		close(file_fd);
		ft_open_file_error();
	}
	close(file_fd);
	return (file_fd);
}
