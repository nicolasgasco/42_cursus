/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:50:12 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 17:16:57 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((*(s1 + i) == *(s2 + i)))
	{
		if (*(s1 + i) == '\0' || *(s2 + i) == '\0')
			break ;
		i++;
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
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
