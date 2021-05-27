/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:55:55 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/26 11:46:59 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void *ft_memccpy(void *restrict dest, const void *restrict src, int c, int n)
{
	int	i;
	i = 0;

	const char	*buf1;
	char 		*buf2;
	
	i = 0;
	buf1 = src;
	buf2 = dest;
	while (i < n && buf2[i] != c)
	{

			printf("FOund!\n");
		if (buf2[i] == c)
		buf2[i] = buf1[i];
		i++;
	}
	printf("\n");
	return (buf2);
}
