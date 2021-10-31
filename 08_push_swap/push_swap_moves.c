/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:42 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 17:57:06 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(num_list *number_list, char move, char list)
{
	if (move == 's')
		ft_s(number_list, list);
	else if (move == 'p')
		ft_p(number_list, list);
	else if (move == 'r')
		ft_r(number_list, list);
	else if (move == 'R')
		ft_rr(number_list, list);
}
