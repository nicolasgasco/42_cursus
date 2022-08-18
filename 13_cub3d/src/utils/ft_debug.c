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

void	ft_write_debug_msg(char *msg)
{
	int		fd;
	size_t	bytes;

	fd = open("./tests/validation_scripts/debug_output", O_WRONLY | O_TRUNC);
	if (fd != -1)
	{
		bytes = write(fd, msg, ft_strlen(msg));
		if (bytes != 0)
			close(fd);
	}
	close(fd);
}

void	ft_write_debug_msg_int(char *msg, int int_arg)
{
	int		fd;
	char	*int_str;

	int_str = ft_itoa(int_arg);
	fd = open("./tests/validation_scripts/debug_output", O_WRONLY | O_APPEND);
	if (fd != -1)
	{
		write(fd, "\n", 1);
		write(fd, msg, ft_strlen(msg));
		write(fd, int_str, ft_strlen(int_str));
		free(int_str);
	}
	else
		free(int_str);
	close(fd);
}
