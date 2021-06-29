/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:55:55 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/29 13:38:42 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	*ft_memccpy(void *restrict dest,
const void *restrict src, int c, size_t n)
{
	unsigned int	i;
	const unsigned char		*buffer1;
	unsigned char			*buffer2;

	i = 0;
	buffer1 = src;
	buffer2 = dest;
	while (i < n && buffer1[i] != (unsigned char)c)
	{
		buffer2[i] = buffer1[i];
		i++;
	}
	if (buffer2[i] == (unsigned char)c)
	{
		i++;
		return (&buffer2[i]);
	}
	return (NULL);
}
