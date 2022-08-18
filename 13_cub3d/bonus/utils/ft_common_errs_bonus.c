/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_errs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/06/09 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

void	ft_malloc_error(void)
{
	ft_putendl_fd("Error: memory error", STDERR_FILENO);
	exit(100);
}

void	ft_open_file_error(void)
{
	ft_putendl_fd("Error: file opening failed", STDERR_FILENO);
	exit(3);
}

void	ft_print_error_exit(t_map *map, char *msg, int err)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_free_allocated_map_data(map);
	exit(err);
}
