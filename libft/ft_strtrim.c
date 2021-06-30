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
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int 	start;
	int		end;
	char	*res;

	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (start < (int)ft_strlen((char *)s1))
	{
		if (!ft_strchr(set, s1[start]))
			break;
		start++;
	}
	while (end > 0)
	{
		if (!ft_strchr(set, s1[end]))
			break;
		end--;
	}
	if (start > end)
		return ("");
	res = malloc((end - start + 1 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (char *)&s1[start], end - start + 1 + 1);
	return res;
}
