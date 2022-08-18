/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:27:49 by jsolinis          #+#    #+#             */
/*   Updated: 2021/11/06 21:15:32 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		if (dstsize && i < (dstsize - 1))
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	if (dstsize)
		dst[j] = '\0';
	return (i);
}
