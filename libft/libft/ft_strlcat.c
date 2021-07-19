/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:44:46 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/29 11:44:04 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	dst_len;

	i = ft_strlen(dst);
	y = 0;
	dst_len = ft_strlen(dst);
	if (size) {
		while (src[y] != '\0' && i < (size - 1))
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = '\0';
	}
	return (dst_len + ft_strlen((char *)src));;
}

