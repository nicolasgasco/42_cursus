/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:10:53 by nicolasg          #+#    #+#             */
/*   Updated: 2021/06/29 23:10:55 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strtrim(char const *s1, char const *set)
{
	int				start;
	unsigned int	end;
	int				i;
	unsigned int	j;
	unsigned int	k;
	char			*res;

	i = 0;
	j = 0;
	k = 0;
	start = -1;
	end = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (start == -1 && set[j] == '\0')
			start = i;
		i++;
	}
	if (i == 0 || (start == -1 && i != 0))
	{
		res = malloc(1 * sizeof(char));
		res[0] = '\0';
		return res;
	}
	i--;
	end = i;
	while (i > start)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (end == (i + k) && set[j] == '\0')
			end = i + 1;
		i--;
		k++;
	}
	res = malloc((end - start + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	j = 0;
	while (j < (end - start + j))
	{
		res[j] = s1[start];
		start++;
		j++;
	}
	res[j] = '\0';
	return res;
}
