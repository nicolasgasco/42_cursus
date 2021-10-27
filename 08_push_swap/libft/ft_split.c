/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:00:34 by nicolasg          #+#    #+#             */
/*   Updated: 2021/07/16 12:35:45 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (tot_words);
}

static void	ft_write_strings_to_array(char const *s, char c, char **result)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
		{
			if (i - start != 0)
			{
				*result = ft_substr(s, start, i - start);
				result++;
			}
			start = i + 1;
		}
		else if (s[i] == c && s[i - 1] == c)
			start++;
		i++;
	}
	if (s[i - 1] != c)
		*result = ft_substr(s, start, i - start);
	if (s[i - 1] != c)
		result++;
	*result = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || ft_calc_total_len(s, c) == 0)
	{
		result = (char **)malloc(sizeof(char *) + 1);
		result[0] = NULL;
		return (result);
	}
	result = (char **)malloc((ft_calc_total_len(s, c) + 1) * sizeof(char *));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_write_strings_to_array(s, c, result);
	free((char *)s);
	return (result);
}