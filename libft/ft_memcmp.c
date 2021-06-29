/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:42:11 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/29 11:37:40 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	unsigned char	*buff1;
	unsigned char	*buff2;

	buff1 = (unsigned char *)s1;
	buff2 = (unsigned char *)s2;
	i = 0;
	while ((buff1[i] == buff2[i]) && i < n - 1)
		i++;
	return (buff1[i] - buff2[i]);
}
