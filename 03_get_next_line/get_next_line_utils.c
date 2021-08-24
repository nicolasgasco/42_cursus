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
	char			*result;
	unsigned int	i;

	if (!s1)
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
	unsigned int	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (len == 0 || start >= len_s || len > (len_s - start))
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
	free((char *)s);
	return (result);
}

char	*ft_strrchr(char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
		i++;
	if (s[i] == '\0' && s[i] != c)
		return (0);
	return ((char *)(s + i + 1));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	while (i++ < len1)
		res[i-1] = s1[i-1];
	i = 0;
	while (i++ < len2)
		res[i - 1 + len1] = s2[i-1];
	res[i - 1 + len1] = '\0';
	free((char *)s1);
	return (res);
}
