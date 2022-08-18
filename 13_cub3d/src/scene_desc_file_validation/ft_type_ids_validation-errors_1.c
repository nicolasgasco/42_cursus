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

void	ft_invalid_col_statement_error_exit(t_map *map, char *line)
{
	free(line);
	ft_free_allocated_map_data(map);
	ft_putendl_fd("Error: invalid color statement", STDERR_FILENO);
	exit(8);
}

void	ft_incomplete_scene_info_error_exit(t_map *map)
{
	ft_free_allocated_map_data(map);
	ft_putendl_fd("Error: incomplete scene info", STDERR_FILENO);
	exit(9);
}

void	ft_duplicate_scene_info_error_exit(t_map *map)
{
	ft_free_allocated_map_data(map);
	ft_putendl_fd("Error: duplicated scene info", STDERR_FILENO);
	exit(10);
}

void	ft_invalid_orientation_path_error_exit(char *line, char *o_path_id,
		char *o_path)
{
	free(line);
	free(o_path_id);
	free(o_path);
	ft_putendl_fd("Error: invalid orientation path", STDERR_FILENO);
	exit(11);
}
