/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:38:27 by ngasco            #+#    #+#             */
/*   Updated: 2021/07/16 09:37:16 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*buffer1;
	char			*buffer2;

	i = 0;
	buffer1 = (char *)src;
	buffer2 = dst;
	while (i < n && (src || dst))
	{
		buffer2[i] = buffer1[i];
		i++;
	}
	return (dst);
}
