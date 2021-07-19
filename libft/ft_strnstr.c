/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:14:52 by ngasco            #+#    #+#             */
/*   Updated: 2021/07/16 09:39:44 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;
	int				found;

	i = 0;
	found = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{	
		j = 0;
		if (*(haystack + i) == *(needle + j))
		{
			found = i;
			while (needle[j] != '\0' && i < len && haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			if (*(needle + j) == '\0')
				return ((char *)(haystack + found));
		}
		i++;
	}
	return (NULL);
}
