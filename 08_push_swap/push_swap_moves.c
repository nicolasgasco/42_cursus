/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:42 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 13:23:50 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_list *number_list, char move, char list)
{
	if (move == 's')
		ft_s(number_list, list);
	else if (move == 'p')
		ft_p(number_list, list);
	else if (move == 'r')
		ft_r(number_list, list);
	else if (move == 'R')
		ft_rr(number_list, list);
	ft_update_stats(number_list);
	// ft_print_struct(number_list);
	if (ft_check_if_sorted(number_list->a_list, number_list->num_tot))
	{
		// printf("Array is sorted! FIN\n");
		// ft_print_struct(number_list);
		exit(1);
	}
}
