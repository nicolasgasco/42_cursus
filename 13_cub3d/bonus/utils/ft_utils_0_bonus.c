/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/06/09 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
#include "../../Libft/libft.h"

int	ft_open_file(char *file_path)
{
	int	file_fd;

	file_fd = open(file_path, O_RDONLY);
	if (file_fd == -1)
	{
		free(file_path);
		ft_open_file_error();
	}
	return (file_fd);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	ft_skip_to_non_space_char(char *line, int *iterator)
{
	while (line[*iterator] != '\0')
	{
		if (ft_isspace(line[*iterator]))
			*iterator += 1;
		else
			return ;
	}
}

char	*ft_substr_no_leaks(char *s, unsigned int start, size_t len)
{
	char	*temp;

	temp = ft_substr(s, start, len);
	free(s);
	return (temp);
}

char	*ft_strtrim_no_leaks(char *s1, const char *set)
{
	char	*temp;

	temp = ft_strtrim(s1, set);
	free(s1);
	return (temp);
}
