/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:38:27 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/26 10:55:26 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int			i;
	const char	*buf1;
	char 		*buf2;
	
	i = 0;
	buf1 = src;
	buf2 = dest;
	while (i < n)
	{
		buf2[i] = buf1[i];
		i++;
	}
	return (dest);
}
