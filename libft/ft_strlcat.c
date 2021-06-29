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

unsigned int ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	const char		*buffer1;
	unsigned int	length;

	i = 0;
	length = 0;
	buffer1 = src;
	while(buffer1[i] != '\0')
		i++;
	length = i;
	i = 0;
	if (size == 0 || length == 0)
		return (0);
	while(i < length && i < (size - 1))
	{
		dst[i] = buffer1[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}

