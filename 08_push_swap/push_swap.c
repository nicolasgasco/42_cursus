/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:05 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:05:02 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_list	number_list;

	number_list.num_moves = 0;
	ft_create_linked_list(argc, argv, &number_list);
	// ft_print_struct(&number_list);
	ft_move(&number_list, 'p', 'b');
	ft_move(&number_list, 'p', 'b');
	ft_move(&number_list, 'p', 'b');
	ft_print_struct(&number_list);
	ft_move(&number_list, 'R', 'a');
	ft_print_struct(&number_list);
	ft_move(&number_list, 'R', 'b');
	ft_print_struct(&number_list);
	ft_move(&number_list, 'R', 'r');
	ft_print_struct(&number_list);
	// ft_move(&number_list, 's', 'a');
	// ft_print_struct(&number_list);
	// ft_move(&number_list, 'p', 'a');
	// ft_print_struct(&number_list);
	// ft_move(&number_list, 'p', 'a');
	// ft_print_struct(&number_list);
	// ft_move(&number_list, 'p', 'a');
	// ft_print_struct(&number_list);
	ft_deallocate_list(&number_list.a_list);
	ft_deallocate_list(&number_list.b_list);
	return (0);
}
