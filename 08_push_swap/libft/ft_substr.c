/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:10:08 by nicolasg          #+#    #+#             */
/*   Updated: 2021/11/16 19:50:46 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*result;

	j = 0;
	if (!s || !len || start >= ft_strlen((char *)s))
	{
		result = malloc(1 * sizeof(char));
		result[0] = '\0';
		return (result);
	}
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (j < len)
	{
		result[j] = s[start];
		start++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
