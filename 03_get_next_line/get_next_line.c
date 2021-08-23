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
#include <string.h>
#define getName(var)  #var

int	ft_find_newline(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (-2);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (i == ft_strlen(s))
		return (-1);
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
	return ((char *)(s + i + 1));
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	if (!s)
		return;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count)
{
	void	*result;

	result = malloc(count * sizeof(char));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_bzero(result, count * sizeof(char));
	return (result);
}



void	iterate_string(char *s, char *name)
{
	int	i;

	i = 0;
	printf("Iterating '%s'...\n.", name);
	while (s[i] != '\0')
	{
		printf("%c", s[i]);
		i++;
	}
	if (s[i] != '\0')
	{
		printf("NULL CHAR MISSING!!");
	}
	printf(".\n");
	return;
}

char *get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	int			read_flag;
	static char	*buf_static;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_flag = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = NULL;

	while (1)
	{
		if (!buf_static || (buf_static && read_flag != 0) )
		{
			if (read(fd, buffer, BUFFER_SIZE) <= 0)
				break;
			read_flag = 1;
			buf_static = ft_strdup(buffer);
		}
		if (ft_find_newline(buf_static) >= 0)
		{
			line = ft_strjoin(line, ft_substr(buf_static, 0, ft_find_newline(buf_static) + 1));
			if (read_flag == 1 && ft_strlen(buf_static) > ft_strlen(line))
			{
				free(buf_static);
				buf_static = ft_strdup(ft_strrchr(buffer, '\n'));
			}
			buf_static = ft_substr(buf_static, 1, ft_strlen(buf_static) - 1);
			if (read_flag != 1)
			{
				buf_static = ft_substr(buf_static, ft_find_newline(buf_static), ft_strlen(buf_static) - ft_find_newline(buf_static));
				buf_static = ft_substr(buf_static, 1, ft_strlen(buf_static) - 1);
				free(buffer);
				return(line);
			}
		}
		else
		{
			if (read_flag == 0)
			{
				line = ft_strdup(buf_static);
				buf_static = NULL;
				return (line);
			}
			line = ft_strjoin(line, buf_static);
		}
	}
	free(buffer);
	if (read_flag == 1)
	{
		line[ft_strlen(line) - 1] = '\n';
		return (line);
	}
	free(buf_static);
	return (NULL);
}
