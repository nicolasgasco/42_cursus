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

void	ft_type_ids_completeness_check(t_map *map)
{
	if (!map->c_color || !map->f_color)
		ft_incomplete_scene_info_error_exit(map);
	else if (!ft_strncmp(map->c_color, map->f_color, ft_strlen(map->c_color)))
		ft_duplicate_scene_info_error_exit(map);
	if (!map->no_path || !map->ea_path || !map->so_path || !map->we_path)
		ft_incomplete_scene_info_error_exit(map);
	ft_check_o_paths_duplicates(map);
}

void	ft_check_o_paths_duplicates(t_map *map)
{
	char	**path_arr;

	path_arr = (char **)malloc(sizeof(char *) * 4);
	if (!path_arr)
	{
		ft_free_allocated_map_data(map);
		ft_malloc_error();
	}
	path_arr[0] = ft_strdup(map->no_path);
	path_arr[1] = ft_strdup(map->ea_path);
	path_arr[2] = ft_strdup(map->so_path);
	path_arr[3] = ft_strdup(map->we_path);
	ft_find_o_paths_duplicates(path_arr, map);
	ft_free_validation_path_arr(path_arr);
}

void	ft_find_o_paths_duplicates(char **path_arr, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i && !ft_strncmp(path_arr[i], path_arr[j],
					ft_strlen(path_arr[i])))
			{
				ft_free_validation_path_arr(path_arr);
				ft_duplicate_scene_info_error_exit(map);
			}
			j++;
		}
		i++;
	}
}

void	ft_free_validation_path_arr(char **path_arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(path_arr[i]);
		i++;
	}
	free(path_arr);
}
