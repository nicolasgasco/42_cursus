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

void	ft_readline_color_codes(int fd, char *line, t_tdata *texture)
{
	int	i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_str_contains_spaced_char(line, 'c'))
		{
			ft_parse_char_col(line, texture);
			free(line);
			i++;
			continue ;
		}
		if (i != 0 && !ft_str_contains_spaced_char(line, 'c'))
		{
			free(line);
			break ;
		}
	}
}

void	ft_parse_char_col(char *line, t_tdata *texture)
{
	struct s_cinfo	*curr;

	curr = texture->col_info_list;
	if (!curr)
	{
		texture->col_info_list = ft_create_col_info_struct(line);
		return ;
	}
	while (curr)
	{
		if (curr->next)
			curr = curr->next;
		else
			break ;
	}
	curr->next = ft_create_col_info_struct(line);
}
