/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:38:36 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:39:22 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_non_num_util(char **num_str, int i)
{
	if (ft_check_non_num(num_str[i]) == 0)
	{
		free(num_str);
		ft_put_err(2);
	}
}

void	ft_check_empty(char c)
{
	if (c == '\0')
		ft_put_err(2);
}
