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

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_skip_to_content(char *line, int *iterator)
{
	if (line)
	{
		while (line[*iterator])
		{
			if (ft_isspace_no_endl(line[*iterator]))
				*iterator += 1;
			else
				return ;
		}
	}
}

int	ft_str_contains_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* Search for a char surronded by x number of spaces */
int	ft_str_contains_spaced_char(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c && ft_isspace(str[i - 1]) && ft_isspace(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_is_not_hex(char *str, int start)
{
	int	i;

	i = start;
	while (str[i] != '\0' && str[i] != '\"')
	{
		if (i > (start + 5))
			return (1);
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
			|| (str[i] > 'F' && str[i] < 'a') || str[i] > 'f')
			return (1);
		i++;
	}
	return (0);
}
