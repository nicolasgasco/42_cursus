/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:09:14 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/24 12:45:01 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void *ft_memset(char *str, int c, size_t n) {
	unsigned int	i;

	char 			*dest;

	dest = str;
	i = 0;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return dest;	
}
