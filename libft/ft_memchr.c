/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:21:04 by ngasco            #+#    #+#             */
/*   Updated: 2021/07/15 16:03:44 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	const char		*buffer;

	i = 0;
	buffer = s;
	while (i < (n - 1) && buffer[i] != c && buffer[i] != '\0')
	{
		i++;
	}
	if (buffer[i] == c)
		return ((void *)&buffer[i]);
	return (0);
}
