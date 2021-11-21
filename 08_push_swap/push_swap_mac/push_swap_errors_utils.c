/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:50:10 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 12:04:28 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_err(int code, char *str)
{
	ft_putstr_fd("Error\n", 0);
	if (str)
		ft_putstr_fd(str, 2);
	exit(code);
}