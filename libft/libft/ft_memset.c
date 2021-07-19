/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:09:14 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/02 12:14:37 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	char			*dest;

	dest = b;
	i = 0;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return ((void *)b);
}
