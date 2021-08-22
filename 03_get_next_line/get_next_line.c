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
	{
		return (-1);
	}
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
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	i = 0;
	read_flag = 0;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	line = NULL;

	if (buf_static)
	{
		// iterate_string(buf_static, "buf_static");
		// printf("Buf_static exists already\n");
	}
	// printf("1a) Buf_static doesn't exist or is empty...\n");
	while (1)
	{
		if (!buf_static || (buf_static && read_flag != 0) )
		{
			if (read(fd, buffer, BUFFER_SIZE) <= 0)
				break;
			read_flag = 1;
			buf_static = ft_strdup(buffer);
		}
		// printf("2) Inside while and just read...\n");
		if (ft_find_newline(buf_static) >= 0)
		{
			// printf("2a) Something was read with a newline...\n");
			line = ft_strjoin(line, ft_substr(buf_static, 0, ft_find_newline(buf_static) + 1));
			if (read_flag == 1)
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
			// printf("%d\n", i);
			// printf("2b) Something was read without newline...\n");
			if (read_flag == 0)
			{
				line = ft_strdup(buf_static);
				buf_static = NULL;
				return (line);
			}
			line = ft_strjoin(line, buf_static);

			// ft_bzero(buf_static);
			// ft_bzero(buffer);
		}
		i++;
	}
	// printf("%d\n", i);
	free(buffer);
	if (read_flag == 1)
	{
		// if (ft_find_newline(line) == -1)
		// {
		// 	printf("4) Entering last if...\n");
		// 	line = ft_strjoin(line, "\n");
		// }
		if (line[ft_strlen(line)] != '\n')
		{
			line = ft_strjoin(line, "\n");
		}
		return (line);
	}
	// printf("5) Reached end of function...\n");
	free(buf_static);
	return (NULL);
}

// char	*get_next_line2(int fd)
// {
// 	char		*buffer;
// 	char		*line;
// 	static char	*buffer_stat;
// 	static size_t		bytes_read;

// 	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
// 		return (NULL);
// 	line = (char *)malloc(sizeof(char *));
// 	ft_bzero(line, sizeof(char *));
// 	buffer = (char *)malloc(BUFFER_SIZE + 1);
// 	ft_bzero(buffer, BUFFER_SIZE + 1);
// 	if (!buffer_stat)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		buffer[ft_strlen(buffer)] = '\0';
// 		buffer_stat = ft_strjoin(buffer_stat, buffer);
// 		if (bytes_read <= 0)
// 		{
// 			free(line);
// 			free(buffer);
// 			return (NULL);
// 		}
// 	}
// 	if (buffer_stat[0] == '\0' || bytes_read <= 0)
// 	{
// 		free(line);
// 		free(buffer);
// 		return (NULL);
// 	}

// 	while (!ft_find_newline(line))
// 	{
// 		if (ft_find_newline(buffer_stat))
// 		{
// 			line = ft_strjoin(line, ft_substr(buffer_stat, 0, ft_find_newline(buffer_stat)));
// 			line[ft_strlen(line)] = '\n';
// 			free(buffer);
// 			if (ft_strrchr(buffer_stat, '\n'))
// 			{
// 				buffer_stat = ft_strrchr(buffer_stat, '\n');
// 				buffer_stat = ft_substr(buffer_stat, 1, ft_strlen(buffer_stat) - 1);
// 			}
// 			else
// 				free(buffer_stat);
// 			return (line);
// 		}
// 		line = ft_strjoin(line, buffer_stat);
// 		ft_bzero(buffer_stat, ft_strlen(buffer_stat) + 1);
// 		free(buffer_stat);
// 		ft_bzero(buffer, BUFFER_SIZE + 1);
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 		{
// 			free(buffer);
// 			if (line[0] == '\0')
// 			{
// 				free(line);
// 				return (NULL);
// 			}
// 			line[ft_strlen(line)] = '\n';
// 			return (line);
// 		}
// 		buffer[ft_strlen(buffer)] = '\0';
// 		buffer_stat = ft_strjoin(buffer_stat, buffer);
// 	}
// 	free(buffer);
// 	free(buffer_stat);
// 	return (line);
// }
