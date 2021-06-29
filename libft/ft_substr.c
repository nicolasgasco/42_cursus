/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:10:08 by nicolasg          #+#    #+#             */
/*   Updated: 2021/06/29 23:10:17 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	j;
	char 			*result;
	unsigned int	length;

	i = start;
	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	length = j;
	j = 0;
	if (start >= length)
	{
		result = malloc(1 * sizeof(char));
		result[0] = '\0';
		return result;
	}
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (j < len)
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
