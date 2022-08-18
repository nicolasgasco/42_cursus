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

void	ft_invalid_id_error_exit(t_map *map, char *line)
{
	free(line);
	ft_free_allocated_map_data(map);
	ft_putendl_fd("Error: invalid identifier", STDERR_FILENO);
	exit(4);
}

void	ft_empty_scene_file_error_exit(void)
{
	ft_putendl_fd("Error: empty scene file", STDERR_FILENO);
	exit(5);
}

void	ft_missing_file_path_error_exit(char *o_path_id, char *line, t_map *map)
{
	free(o_path_id);
	free(line);
	ft_free_allocated_map_data(map);
	ft_putendl_fd("Error: missing file path", STDERR_FILENO);
	exit(6);
}

void	ft_invalid_color_code_error_exit(t_map *map, char *line,
	char *col_code_str)
{
	ft_free_allocated_map_data(map);
	free(line);
	free(col_code_str);
	ft_putendl_fd("Error: invalid color code", STDERR_FILENO);
	exit(7);
}
