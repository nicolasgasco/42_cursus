/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:14:15 by ngasco            #+#    #+#             */
/*   Updated: 2021/08/19 18:16:08 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
    char	*buffer;
    char	*line;
	size_t	bytes_read;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	bytes_read = 1;
    line = (char *)malloc(sizeof(char *));
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ft_bzero(line, sizeof(char *));
	ft_bzero(buffer, sizeof(char) * (BUFFER_SIZE + 1));

	while (bytes_read > 0)
    {
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			free(buffer);
			if (line[1] != '\0')
			{
				return (line);
			}		
			return (0);
		}
        if (ft_find_newline(buffer))
        {
			line = ft_strjoin(line, ft_substr(buffer, 0, ft_find_newline(buffer)));
			line = ft_strjoin(line, "\n");
			free(buffer);
            return (line);
        } else {
			line = ft_strjoin(line, buffer);
        }
    }
	return (NULL);
}
