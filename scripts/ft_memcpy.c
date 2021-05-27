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
	const char	*buffer1;
	char 		*buffer2;
	
	i = 0;
	buffer1 = src;
	buffer2 = dest;
	while (i < n)
	{
		buffer2[i] = buffer1[i];
		i++;
	}
	return (dest);
}
