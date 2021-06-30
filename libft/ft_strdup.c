/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:00:17 by nicolasg          #+#    #+#             */
/*   Updated: 2021/06/30 16:00:19 by nicolasg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen((char *)s);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
