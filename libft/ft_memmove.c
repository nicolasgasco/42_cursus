/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:20:44 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/02 12:40:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	const char		*buffer1;
	char			*buffer2;
	char			*temp_buffer;

	i = 0;
	temp_buffer = (char *)src;
	buffer1 = src;
	buffer2 = dest;
	while (i < n)
	{
		temp_buffer[i] = buffer1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		buffer2[i] = temp_buffer[i];
		i++;
	}
	return (dest);
}
