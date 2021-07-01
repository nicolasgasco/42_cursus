/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:13:51 by nicolasg          #+#    #+#             */
/*   Updated: 2021/07/01 15:13:57 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL) ;
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return res;
}
