/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:10:53 by nicolasg          #+#    #+#             */
/*   Updated: 2021/07/16 09:59:16 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (start < (int)ft_strlen((char *)s1))
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	return (start);
}

static int	ft_calc_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen((char *)s1) - 1;
	while (end > 0)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!set)
		return (NULL);
	if (!s1)
	{
		res = malloc(1 * sizeof(char));
		res[0] = '\0';
		free((char *)s1);
		return (res);
	}
	end = ft_calc_end(s1, set);
	start = ft_calc_start(s1, set);
	if (start > end)
	{
		res = malloc(1 * sizeof(char));
		res[0] = '\0';
		free((char *)s1);
		return (res);
	}
	res = malloc((end - start + 1 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (char *)&s1[start], end - start + 1 + 1);
	free((char *)s1);
	return (res);
}
