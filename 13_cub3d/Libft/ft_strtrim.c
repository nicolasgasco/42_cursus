/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:05:58 by jsolinis          #+#    #+#             */
/*   Updated: 2021/11/12 16:38:59 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		head = 0;
		tail = ft_strlen(s1);
		while (s1[head] && ft_strchr(set, s1[head]))
			head++;
		while (s1[tail - 1] && ft_strchr(set, s1[tail - 1]) && tail > head)
			tail--;
		str = (char *) malloc (sizeof(char) * (tail - head + 1));
		if (str)
			ft_strlcpy(str, &s1[head], tail - head + 1);
	}
	return (str);
}
