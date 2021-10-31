#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct NumList {
	int			num_moves;
	int			num_tot;
	int			lo_tot;
	int			hi_tot;
	struct Node	*a_list;
	int			lo_a;
	int			hi_a;
	struct Node	*b_list;
	int			lo_b;
	int			hi_b;
}	num_list;

struct Node {
	int			x;
	struct Node	*next;
};

// Libft
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);

// Linked list methods
void	ft_insert_beginning(struct Node **root, int value);
void	ft_insert_end(struct Node **root, int value);
void	ft_deallocate_list(struct Node **root);
void	ft_iterate_list(struct Node *root, char c);
void	ft_insert_after(struct Node *node, int value);
void	ft_swap_nodes(struct Node **root, int i1, int i2);
void	ft_remove_node(struct Node **root, int value);

// Rules
void	ft_put_move(num_list *number_list, char move, char list);
void	ft_s(num_list *number_list, char c);
void	ft_p(num_list *number_list, char c);
void	ft_r(num_list *number_list, char c);
void	ft_rr(num_list *number_list, char c);

// Push swap
void	ft_create_linked_list(int argc, char **args, num_list *num_list);
void	ft_move(num_list *number_list, char list, char move);

// To delete
void	ft_print_struct(num_list *number_list);
void	ft_print_int_array(int *arr, int n);

#endif
