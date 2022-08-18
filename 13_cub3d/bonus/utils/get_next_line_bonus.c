/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:39:54 by jsolinis          #+#    #+#             */
/*   Updated: 2022/07/11 13:39:56 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_malloc_char(void)
{
	char	*ret;

	ret = malloc(1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

int	check_ch(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_aux(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *) malloc (2 + i);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buff;
	int		filed;

	if (fd < 0)
		return (NULL);
	line = ft_malloc_char();
	line[0] = '\0';
	filed = 1;
	while (!(check_ch(line)) && filed != 0)
	{
		filed = read(fd, &buff, 1);
		if (filed <= 0)
		{
			if (line[0] == '\0' || filed == -1)
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		line = ft_aux(line, buff);
	}
	return (line);
}
