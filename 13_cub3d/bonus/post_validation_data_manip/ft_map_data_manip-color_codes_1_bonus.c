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

struct s_cinfo	*ft_create_col_info_struct(char *line)
{
	int				i;
	char			col_char;
	char			*col_hex;

	i = 0;
	col_hex = NULL;
	col_char = line[i + 1];
	if (!ft_isspace(line[i + 2]))
		ft_double_color_id_error();
	while (line[i] != '\0')
	{
		if (line[i] == 'c' && i != 1)
		{
			while (line[i] != ' ')
				i++;
			ft_skip_to_non_space_char(line, &i);
			if (line[i] != '#' || ft_str_is_not_hex(line, i + 1))
				ft_color_not_valid_error();
			col_hex = ft_substr(line, i + 1, 6);
			break ;
		}
		i++;
	}
	return (ft_populate_col_info(col_char, col_hex));
}

void	ft_double_color_id_error(void)
{
	ft_putendl_fd("Error: texture file is invalid", STDERR_FILENO);
	exit(12);
}

struct s_cinfo	*ft_populate_col_info(char col_char, char *col_hex)
{
	struct s_cinfo	*col_info;

	col_info = malloc(sizeof(struct s_cinfo));
	col_info->col_char = col_char;
	col_info->col_int = ft_hex_str_to_int(col_hex);
	free(col_hex);
	col_info->next = NULL;
	return (col_info);
}

int	ft_hex_str_to_int(char *hex)
{
	int	curr_digit;
	int	num_digits;
	int	i;
	int	result;

	i = 0;
	result = 0;
	num_digits = ft_strlen(hex) - 1;
	while (hex[i] != '\0')
	{
		if ((hex[i] >= 'A' && hex[i] <= 'F'))
			curr_digit = hex[i] - UPPERCASE_DIGIT_DIFF;
		else if ((hex[i] >= 'a' && hex[i] <= 'f'))
			curr_digit = hex[i] - LOWERCASE_DIGIT_DIFF;
		else if (hex[i] >= '0' && hex[i] <= '9')
			curr_digit = hex[i] - '0';
		else
			curr_digit = 0;
		result += curr_digit * (int)pow((float)16, (float)num_digits);
		num_digits--;
		i++;
	}
	return (result);
}
