/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:01:54 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:39:11 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct NumList {
	int				num_moves;
	int				num_tot;
	int				lo_tot;
	int				hi_tot;
	struct s_node	*o_list;
	struct s_node	*a_list;
	int				a_len;
	int				lo_a;
	int				hi_a;
	struct s_node	*b_list;
	int				b_len;
	int				lo_b;
	int				hi_b;
}	t_list;

struct s_node {
	int				x;
	int				i;
	struct s_node	*next;
};

// Libft
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);

// Linked list methods
void	ft_insert_beginning(struct s_node **root, int value);
void	ft_insert_end(struct s_node **root, int value);
void	ft_insert_after(struct s_node *node, int value);
void	ft_swap_nodes(struct s_node **root, int i1, int i2);
void	ft_remove_node(struct s_node **root, int value);
void	ft_deallocate_list(struct s_node **root);
void	ft_free_lists(t_list *n_list);
int		ft_get_value(struct s_node *list, int index);
int		*ft_bubble_sort(int *num_arr, int limit);
void	ft_assign_i(struct s_node *linked, int *array, int limit);
void	ft_assign_i_linked(struct s_node *list, struct s_node *ordered);

// Rules
void	ft_put_move(t_list *number_list, char move, char list);
void	ft_s(t_list *number_list, char c);
void	ft_p(t_list *number_list, char c);
void	ft_r(t_list *number_list, char c);
void	ft_rr(t_list *number_list, char c);

// Validation
int		ft_check_non_num(char *s);
int		ft_check_repetition(int *nums, int limit);
int		ft_check_size(int list_size);
void	ft_put_err(int code);
int		ft_check_if_sorted(struct s_node *a_list, int size);
int		ft_check_if_sorted_arr(int *array, int size);
void	ft_check_non_num_util(char *num_str);
void	ft_check_empty(char c);

// List stats
void	ft_update_stats(t_list *n_list);
int		ft_list_len(struct s_node *root);
int		ft_find_hilo(struct s_node *root, char flag);
void	ft_initialize_stats(t_list *n_list);

// Sorting
void	ft_sort_two(t_list *n_list);
void	ft_sort_three(t_list *n_list);
void	ft_sort_four(t_list *n_list);
void	ft_sort_five(t_list *n_list);
void	ft_sort_six(t_list *n_list);
void	ft_sort_seven(t_list *n_list);
void	ft_radix_sort(t_list *n_list);
void	ft_choose_direction(t_list *n_list, struct s_node *list, int value);
void	ft_radix_choose_direction(int i, int comp, t_list *n_list);

// Push swap
void	ft_create_linked_list(int argc, char **args, t_list *t_list);
void	ft_move(t_list *number_list, char list, char move);

// Not part of official assignment
void	ft_print_struct(t_list *number_list);
void	ft_print_int_array(int *arr, int n);
void	ft_put_bin(int n);
void	ft_put_bin_list(struct s_node *root);
void	ft_iterate_list(struct s_node *root, char c);

#endif
