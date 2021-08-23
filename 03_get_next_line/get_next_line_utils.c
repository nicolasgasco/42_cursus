/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:14:02 by ngasco            #+#    #+#             */
/*   Updated: 2021/08/21 16:26:31 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	unsigned int	i;

	if (s1 == NULL)
		return (NULL);
	result = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*result;

	if (!s || len == 0 || start >= ft_strlen((char *)s)
	|| len > ft_strlen((char *)s) - start)
		return (NULL);
	j = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	while (j < len)
	{
		result[j] = s[start];
		start++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	while (i++ < ft_strlen(s1))
		res[i-1] = s1[i-1];
	i = 0;
	while (i++ < ft_strlen(s2))
		res[i - 1 + ft_strlen(s1)] = s2[i-1];
	res[i - 1 + ft_strlen(s1)] = '\0';
	return (res);
}
