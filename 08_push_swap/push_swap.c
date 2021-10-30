#include "push_swap.h"
#include <stdio.h>

void ft_print_struct(num_list *number_list)
{
	printf("\n");
	ft_iterate_list(number_list->a_list, 'a');
	ft_iterate_list(number_list->b_list, 'b');
	printf("Num tot is %d\n", number_list->num_tot);
	printf("Num moves is %d\n", number_list->num_moves);
	printf("\n");
}

int main(int argc, char *argv[])
{
	num_list number_list;
	num_list *ptr;

	ptr = &number_list;
	ft_create_linked_list(argc, argv, &number_list);
	ft_print_struct(ptr);
	ft_move(&number_list, 's', 's');
	ft_print_struct(ptr);

	return (0);
}