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

void	ft_scene_desc_file_validation(int argc, char *file_path, t_map *map)
{
	ft_write_debug_msg("Starting validation");
	ft_check_num_args(argc);
	ft_file_extension_validation(file_path);
	ft_type_ids_validation(file_path, map);
	ft_type_ids_completeness_check(map);
	ft_write_debug_msg("Type ids validated successfully");
	ft_map_content_validation(file_path, map);
	ft_write_debug_msg("Scene file validated successfully");
}

void	ft_check_num_args(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error: arguments", STDERR_FILENO);
		exit(1);
	}
}

void	ft_file_extension_validation(char *file_path)
{
	int		ext_len;
	int		ext_start;
	char	*file_path_ext;

	ext_len = ft_strlen(".cub");
	ext_start = ft_strlen(file_path) - ext_len;
	if (ext_start == 0)
		ft_invalid_extension_error_exit();
	file_path_ext = ft_substr(file_path, ext_start, ext_len);
	if (ft_strncmp(file_path_ext, ".cub", ext_len) != 0)
	{
		free(file_path_ext);
		ft_invalid_extension_error_exit();
	}
	free(file_path_ext);
}

void	ft_invalid_extension_error_exit(void)
{
	ft_putendl_fd("Error: invalid extension", STDERR_FILENO);
	exit(2);
}
