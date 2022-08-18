/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content_validation-map_size.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:45:46 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:45:50 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_validate_size(t_map *map)
{
	if (map->height < 3)
		ft_print_error_exit(map,
			"Error. Incorrect map size: height must be over 3 rows", 11);
	if (map->width < 3)
		ft_print_error_exit(map,
			"Error. Incorrect map size: width must be over 3 columns", 12);
}
