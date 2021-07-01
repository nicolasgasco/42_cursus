/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:00:34 by nicolasg          #+#    #+#             */
/*   Updated: 2021/06/30 16:00:36 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_calc_total_len(char const *s, char c)
{
	int	res;
	int	i;
	int	tot_words;

	tot_words = 0;
	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			res++;
		else if (s[i] == c && s[i - 1] && s[i - 1] != c)
			tot_words++;
		i++;
	}
	if (s[i - 1] != c)
		tot_words += 1;
	return (tot_words + res);
}

static void	ft_write_strings_to_array(char const *s, char c, char **result)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
		{
			if (i - start != 0)
			{
				result[j] = ft_substr(s, start, i - start);
				j++;
			}
			start = i + 1;
		}
		else if (s[i] == c && s[i - 1] == c)
			start++;
		i++;
	}
	if (s[i - 1] != c)
	{
		result[j] = ft_substr(s, start, i - start);
		j++;
	}
	result[j] = NULL;
}

char **ft_split(char const *s, char c)
{
	char	**result;

	if (!s || !c)
		return (NULL);
	result = malloc(ft_calc_total_len(s, c) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_write_strings_to_array(s, c, result);
	return result;
}
