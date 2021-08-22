/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:44:46 by ngasco            #+#    #+#             */
/*   Updated: 2021/07/16 09:32:42 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	dst_len;

	i = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	y = 0;
	if (dstsize && ft_strlen(dst) <= dstsize)
	{
		while (src[y] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = '\0';
	}
	if (dstsize == 0)
		dst_len = 0;
	if (dstsize < dst_len)
		dst_len = dstsize;
	return (dst_len + ft_strlen((char *)src));
}
