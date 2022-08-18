/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:31:00 by jsolinis          #+#    #+#             */
/*   Updated: 2021/09/09 11:36:46 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	substr = (char *) malloc(len + 1);
	if (substr == NULL || s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		*substr = '\0';
	else
	{
		while (len > 0)
		{
			substr[i] = s[start + i];
			i++;
			len--;
		}
	}
	substr[i] = '\0';
	return (substr);
}
