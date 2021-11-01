/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:44:07 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/01 16:16:17 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*ft_populate_s_nodes(int *num_arr, int n)
{
	struct s_node	*root;
	int			i;

	if (!num_arr)
		return (NULL);
	root = malloc(sizeof(struct s_node));
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
		if (ft_check_if_num(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 0);
			exit(0);
		}
		result[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (result);
}

void	ft_create_linked_list(int argc, char **args, t_list *n_list)
{
	int		*num_arr;

	if (argc > 2)
		num_arr = ft_create_num_arr(argc, args);
	else
	{
		num_arr = ft_create_num_arr(argc, args);
	}
	if (ft_check_repetition(num_arr, (argc - 1)) == 0)
	{
		ft_putstr_fd("Error\n", 0);
		exit(1);
	}
	ft_print_int_array(num_arr, argc - 1);
	n_list->num_tot = argc - 1;
	n_list->a_list = ft_populate_s_nodes(num_arr, n_list->num_tot);
	return ;
}
