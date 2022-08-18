/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:55:28 by jsolinis          #+#    #+#             */
/*   Updated: 2021/07/01 11:22:58 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_c;
	int		i;
	char	*str;

	c_c = (char) c;
	i = 0;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == c_c)
			return (str + i);
		i++;
	}
	if (str[i] == c_c)
		return (str + i);
	else
		return (0);
}
