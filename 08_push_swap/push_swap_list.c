/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:44:07 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/13 12:26:56 by ngasco           ###   ########.fr       */
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

int	*ft_create_num_arr(int argc, char *argv[], t_list *n_list)
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

int	*ft_create_str_arr(char *str, t_list *n_list)
{
	int		i;
	char	**num_str;
	int		*result;

	i = 0;
	if (ft_check_character(str, ','))
		num_str = ft_split(str, ',');
	else
		num_str = ft_split(str, ' ');
	while (num_str[i] != NULL)
		i++;
	result = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (num_str[i] != NULL)
	{
		result[i] = ft_atoi(ft_strtrim(num_str[i], " "));
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
		exit(2);
	if (argc == 2)
		num_arr = ft_create_str_arr(args[1], n_list);
	else
		num_arr = ft_create_num_arr(argc, args, n_list);
	if (ft_check_repetition(num_arr, n_list->num_tot) == 0)
		ft_put_err(1);
	n_list->a_list = ft_populate_s_nodes(num_arr, n_list->num_tot);
	n_list->o_list = ft_populate_s_nodes(num_arr, n_list->num_tot);
	num_arr = ft_bubble_sort(num_arr, n_list->num_tot);
	// ft_print_int_array(num_arr, n_list->num_tot);
	ft_assign_i(n_list->o_list, num_arr, n_list->num_tot);
	ft_initialize_stats(n_list);
	if (ft_check_size(n_list->num_tot) == 0)
		ft_put_err(1);
	free(num_arr);
	return ;
}
