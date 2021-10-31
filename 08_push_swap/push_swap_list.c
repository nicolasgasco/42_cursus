/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:44:07 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/31 16:55:30 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct Node	*ft_populate_nodes(int *num_arr, int n)
{
	struct Node	*root;
	int			i;

	if (!num_arr)
		return (NULL);
	root = malloc(sizeof(struct Node));
	root->x = num_arr[0];
	i = 1;
	while (i < n)
	{
		ft_insert_end(&root, num_arr[i]);
		i++;
	}
	free(num_arr);
	return (root);
}

int	*ft_create_num_arr(int argc, char *argv[])
{
	int		*result;
	int		i;

	i = 1;
	result = (int *)malloc(sizeof(int) * (argc - 1));
	if (result == NULL)
		exit(1);
	while (i < argc)
	{
		result[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (result);
}

void	ft_create_linked_list(int argc, char **args, num_list *num_list)
{
	int		*num_arr;

	if (argc > 2)
		num_arr = ft_create_num_arr(argc, args);
	else
	{
		// Change this with case when there is a single string with many numbers
		num_arr = ft_create_num_arr(argc, args);
	}
	ft_print_int_array(num_arr, argc - 1);
	num_list->num_tot = argc - 1;
	num_list->a_list = ft_populate_nodes(num_arr, num_list->num_tot);
	return ;
}
