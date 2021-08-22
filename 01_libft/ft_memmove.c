/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:20:44 by ngasco            #+#    #+#             */
/*   Updated: 2021/07/16 09:41:44 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*buffer1;
	char			*buffer2;

	i = len;
	buffer1 = (char *)src;
	buffer2 = (char *)dst;
	if (dst == src)
		return (dst);
	else if (buffer2 > buffer1)
	{
		while (i-- > 0)
			*(buffer2 + i) = *(buffer1 + i);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(buffer2 + i) = *(buffer1 + i);
			i++;
		}
	}
	return (buffer2);
}
