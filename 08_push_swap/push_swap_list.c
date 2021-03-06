/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:44:07 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:38:24 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_node	*ft_populate_s_nodes(int *num_arr, int n)
{
	struct s_node	*root;
	int				i;

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
	return (root);
}

int	*ft_args_are_nums(int argc, char *argv[], t_list *n_list)
{
	int		*result;
	int		i;

	i = 1;
	result = (int *)malloc(sizeof(int) * (argc - 1));
	if (result == NULL)
		exit(1);
	while (i < argc)
	{	
		if (ft_check_non_num(argv[i]) == 0)
		{
			free(result);
			ft_put_err(2);
		}
		result[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	n_list->num_tot = argc - 1;
	return (result);
}

int	ft_check_character(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	*ft_arg_is_str(char *str, t_list *n_list)
{
	int		i;
	char	**num_str;
	int		*result;

	ft_check_empty(str[0]);
	num_str = ft_split(str, ' ');
	i = 0;
	while (num_str[i] != NULL)
	{
		ft_check_non_num_util(num_str, i);
		i++;
	}
	if (i == 1)
		exit(1);
	result = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (num_str[i] != NULL)
	{
		result[i] = ft_atoi(num_str[i]);
		i++;
	}
	n_list->num_tot = i;
	free(num_str);
	return (result);
}

void	ft_create_linked_list(int argc, char **args, t_list *n_list)
{
	int		*num_arr;

	if (argc == 1)
		exit(1);
	if (argc == 2)
		num_arr = ft_arg_is_str(args[1], n_list);
	else
		num_arr = ft_args_are_nums(argc, args, n_list);
	if (ft_check_repetition(num_arr, n_list->num_tot) == 0)
	{
		free(num_arr);
		ft_put_err(3);
	}
	if (ft_check_if_sorted_arr(num_arr, n_list->num_tot) == 1)
	{
		free(num_arr);
		exit(4);
	}
	n_list->a_list = ft_populate_s_nodes(num_arr, n_list->num_tot);
	n_list->o_list = ft_populate_s_nodes(num_arr, n_list->num_tot);
	num_arr = ft_bubble_sort(num_arr, n_list->num_tot);
	ft_assign_i(n_list->o_list, num_arr, n_list->num_tot);
	free(num_arr);
	ft_initialize_stats(n_list);
}
