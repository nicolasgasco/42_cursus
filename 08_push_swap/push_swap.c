/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:05 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:01:15 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	num_list;

	num_list.num_moves = 0;
	ft_create_linked_list(argc, argv, &num_list);
	if (num_list.num_tot == 2)
		ft_sort_two(&num_list);
	else if (num_list.num_tot == 3)
		ft_sort_three(&num_list);
	else if (num_list.num_tot == 4)
		ft_sort_four(&num_list);
	else if (num_list.num_tot == 5)
		ft_sort_five(&num_list);
	else if (num_list.num_tot == 6)
		ft_sort_six(&num_list);
	else if (num_list.num_tot == 7)
		ft_sort_seven(&num_list);
	else
		ft_radix_sort(&num_list);
	ft_free_lists(&num_list);
	return (0);
}
