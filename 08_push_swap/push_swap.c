/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:05 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 12:16:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_list	num_list;

	num_list.num_moves = 0;
	ft_create_linked_list(argc, argv, &num_list);
	ft_print_struct(&num_list);
	if (num_list.num_tot == 2)
	{
		printf("There are 2 elements\n");
		ft_sort_two(&num_list);
	}
	// if (num_list.num_tot == 3)
	// {
	// 	printf("There are 3 elements\n");
	// 	ft_sort_three(&num_list);
	// }
	ft_radix_sort(&num_list);
	// ft_move(&num_list, 's', 'a');
	// ft_move(&num_list, 's', 'a');
	// ft_move(&num_list, 'p', 'b');
	// ft_move(&num_list, 'p', 'b');
	// ft_move(&num_list, 'r', 'r');
	// ft_move(&num_list, 'R', 'r');
	// ft_move(&num_list, 's', 'a');
	// ft_move(&num_list, 'p', 'a');
	// ft_move(&num_list, 'p', 'a');
	// ft_move(&num_list, 'p', 'a');
	ft_deallocate_list(&num_list.a_list);
	ft_deallocate_list(&num_list.b_list);
	return (0);
}
