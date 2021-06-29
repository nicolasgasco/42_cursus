/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:10:32 by nicolasg          #+#    #+#             */
/*   Updated: 2021/06/29 23:10:33 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	tot_length;
	unsigned int	i;
	unsigned int	j;
	char			*res;
	i = 0;
	j = 0;
	tot_length = 0;
	while (s1[i] != '\0')
		i++;
	tot_length += i;
	i = 0;
	while (s2[i] != '\0')
		i++;
	tot_length += i;
	res = malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return res;
}
