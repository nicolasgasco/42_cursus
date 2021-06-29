/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:38:27 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/29 09:28:47 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	*ft_memcpy(void *restrict dest, const void *restrict *src, size_t n)
{
	unsigned int	i;
	const char		*buffer1;
	char			*buffer2;

	i = 0;
	buffer1 = (char *)src;
	buffer2 = dest;
	while (i < n && (src || dest))
	{
		buffer2[i] = buffer1[i];
		i++;
	}
	return (dest);
}
