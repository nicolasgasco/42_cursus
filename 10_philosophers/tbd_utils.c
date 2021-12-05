#include "philo.h"

void    ft_print_struct(t_data *common_data)
{
    printf("\n");
    printf("Number of philosophers: %d\n", common_data->n_philos);
    printf("Time to death: %d\n", common_data->t_death);
    printf("Time to eat: %d\n", common_data->t_eat);
    printf("Time to sleep: %d\n", common_data->t_sleep);
    printf("Number of eats: %d\n", common_data->n_eats);
    // printf("seconds : %ld\nmicro seconds : %d\n\n", common_data->t_start.tv_sec, common_data->t_start.tv_usec);
    printf("\n");
}