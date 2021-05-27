/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:09:14 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/26 09:36:14 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(char *str, int c, size_t n)
{
	unsigned int	i;
	char			*dest;

	dest = str;
	i = 0;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (str);
}
