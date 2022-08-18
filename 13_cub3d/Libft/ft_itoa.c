/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:01:06 by jsolinis          #+#    #+#             */
/*   Updated: 2021/07/01 11:14:56 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_decimals(long n)
{
	int	d;

	d = 0;
	if (n <= 0)
		++d;
	while (n != 0)
	{
		++d;
		n = n / 10;
	}
	return (d);
}

static int	ft_is_negative(char *s, long n)
{
	if (n < 0)
	{
		*s = '-';
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nlong;

	nlong = n;
	len = ft_get_decimals(nlong);
	str = (char *) malloc (sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	else
	{	
		str[len] = '\0';
		if (ft_is_negative(str, nlong))
			nlong *= -1;
		if (nlong == 0)
			str[0] = '0';
	}
	while (nlong != 0)
	{
		--len;
		str[len] = (nlong % 10) + '0';
		nlong = nlong / 10;
	}
	return (str);
}
