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

void	ft_validate_parse_o_path(char *line, int *i, t_map *map)
{
	char	*o_path_id;

	o_path_id = ft_substr(line, *i, 2);
	*i += 2;
	if (ft_check_o_path_already_assigned(map, o_path_id) == 1)
	{
		free(o_path_id);
		free(line);
		ft_duplicate_scene_info_error_exit(map);
	}
	if (ft_strncmp(o_path_id, "NO", 2) == 0)
		map->no_path = ft_validate_o_path(map, o_path_id, line, i);
	else if (ft_strncmp(o_path_id, "SO", 2) == 0)
		map->so_path = ft_validate_o_path(map, o_path_id, line, i);
	else if (ft_strncmp(o_path_id, "WE", 2) == 0)
		map->we_path = ft_validate_o_path(map, o_path_id, line, i);
	else if (ft_strncmp(o_path_id, "EA", 2) == 0)
		map->ea_path = ft_validate_o_path(map, o_path_id, line, i);
	else
	{
		free(o_path_id);
		ft_invalid_id_error_exit(map, line);
	}
	free(o_path_id);
}

char	*ft_validate_o_path(t_map *map, char *o_path_id, char *line, int *i)
{
	char	*o_path;

	if (!ft_isspace(line[*i]))
	{
		free(o_path_id);
		ft_invalid_id_error_exit(map, line);
	}
	ft_skip_to_non_space_char(line, i);
	if (line[*i] == '\0')
		ft_missing_file_path_error_exit(o_path_id, line, map);
	o_path = ft_parse_valid_path(map, o_path_id, line, i);
	return (o_path);
}

char	*ft_parse_valid_path(t_map *map, char *o_path_id, char *line, int *i)
{
	char	*o_path;
	int		path_len;

	path_len = ft_calc_path_length(line, *i);
	o_path = ft_substr(line, *i, path_len);
	*i += path_len;
	o_path = ft_strtrim_no_leaks(o_path, " \n");
	ft_validate_f_path(map, o_path, line, o_path_id);
	ft_skip_to_non_space_char(line, i);
	if (!ft_isspace(line[*i]) && line[*i] != '\0')
	{
		ft_free_allocated_map_data(map);
		ft_invalid_orientation_path_error_exit(line, o_path_id, o_path);
	}
	return (o_path);
}
