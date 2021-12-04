#include "philo.h"

void    ft_print_struct(t_data *philo)
{
    printf("\n");
    printf("Number of philosophers: %d\n", philo->n_philos);
    printf("Time to death: %d\n", philo->t_death);
    printf("Time to eat: %d\n", philo->t_eat);
    printf("Time to sleep: %d\n", philo->t_sleep);
    printf("Number of eats: %d\n", philo->n_eats);
    printf("seconds : %ld\nmicro seconds : %d\n\n", philo->t_start.tv_sec, philo->t_start.tv_usec);
    printf("\n");
}