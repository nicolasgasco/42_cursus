/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:46:29 by jsolinis          #+#    #+#             */
/*   Updated: 2021/11/06 21:30:50 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;

	size = ft_strlen(s1);
	ptr = (char *) malloc (sizeof(char) * size + 1);
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, s1, size + 1);
	return (ptr);
}
