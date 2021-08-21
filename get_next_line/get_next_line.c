/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:14:15 by ngasco            #+#    #+#             */
/*   Updated: 2021/08/21 16:23:31 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_find_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (i == 0 && s[0] == '\n')
		return (1);
	if (s[i] == '\0')
		return (0);
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
		i++;
	if (s[i] == '\0' && s[i] != c)
		return (0);
	return ((char *)(s + i));
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*buffer_stat;
	static size_t		bytes_read;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = (char *)malloc(sizeof(char *));
	ft_bzero(line, sizeof(char *));
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!buffer_stat)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[ft_strlen(buffer)] = '\0';
		buffer_stat = ft_strjoin(buffer_stat, buffer);
		if (bytes_read <= 0)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
	}
	if (buffer_stat[0] == '\0' || bytes_read <= 0)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	while (!ft_find_newline(line))
	{
		if (ft_find_newline(buffer_stat))
		{
			line = ft_strjoin(line, ft_substr(buffer_stat, 0, ft_find_newline(buffer_stat)));
			line[ft_strlen(line)] = '\n';
			free(buffer);
			if (ft_strrchr(buffer_stat, '\n'))
			{
				buffer_stat = ft_strrchr(buffer_stat, '\n');
				buffer_stat = ft_substr(buffer_stat, 1, ft_strlen(buffer_stat) - 1);
			}
			else
				free(buffer_stat);
			return (line);
		}
		line = ft_strjoin(line, buffer_stat);
		ft_bzero(buffer_stat, ft_strlen(buffer_stat) + 1);
		free(buffer_stat);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			line[ft_strlen(line)] = '\n';
			return (line);
		}
		buffer[ft_strlen(buffer)] = '\0';
		buffer_stat = ft_strjoin(buffer_stat, buffer);
	}
	free(buffer);
	free(buffer_stat);	
	return (line);
}
