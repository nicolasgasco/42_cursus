/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:43:05 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 18:01:12 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	num_list	number_list;
	num_list	*ptr;

	ptr = &number_list;
	ft_create_linked_list(argc, argv, &number_list);
	ft_print_struct(ptr);
	ft_move(&number_list, 'R', 'a');
	ft_print_struct(ptr);
	return (0);
}
