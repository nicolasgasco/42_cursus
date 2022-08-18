/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_content_validation-allowed_chars.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:46:38 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:46:41 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../Libft/libft.h"

void	ft_check_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map_content[i][j])
		{
			if (!ft_is_valid_map_char(map->map_content[i][j]))
				ft_print_error_exit(map,
					"Error. Use of forbidden characters.", 14);
			j++;
		}
		i++;
	}
}
