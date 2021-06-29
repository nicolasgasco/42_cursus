/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:43:06 by ngasco            #+#    #+#             */
/*   Updated: 2021/06/07 09:43:34 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void 			*result;

	result = malloc(nmemb * size);
	if (result == NULL)
		return NULL ;
	ft_bzero(result, nmemb * size);
	return result;
}
