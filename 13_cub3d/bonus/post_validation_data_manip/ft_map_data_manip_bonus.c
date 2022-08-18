/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/07/19 12:52:06 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_post_validation_data_manip(t_map *map)
{
	map->rdata->c_col_int = ft_rgb_str_to_int(map->c_color);
	ft_write_debug_msg_int("Ceiling color is ", map->rdata->c_col_int);
	map->rdata->f_col_int = ft_rgb_str_to_int(map->f_color);
	ft_write_debug_msg_int("Floor color is ", map->rdata->f_col_int);
	ft_validate_texture_files(map);
	ft_parse_all_texture_files(map);
}
