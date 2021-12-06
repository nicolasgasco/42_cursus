#include "philo.h"

// void ft_start_eating(t_philo *philo, unsigned int index)
// {
//     int mutex_res;

//     printf("Philosopher %d wants to eat\n", philo->i_philo);
//     mutex_res = pthread_mutex_lock(&philo->common_data.fork_mutex);
//     printf("Mutex res is %d\n", mutex_res);
//     if (mutex_res)
//     {
//         printf("Mutex failed!\n");
//     }
//     philo->fork = 2;
// }

// int ft_get_x_fork(t_philo *philo, int index)
// {
//     if (index < 0)
//         return (philo->forks[index + philo->n_philos]);
//     else if (index >= philo->n_philos)
//         return (philo->forks[index - philo->n_philos]);
//     return (philo->forks[index]);
// }

// void    ft_take_fork(t_philo *philo, int index)
// {
//     if (index < 0)
//         philo->forks[index + philo->n_philos] = 0;
//     else if (index >= philo->n_philos)
//         philo->forks[index - philo->n_philos] = 0;
//     else
//         philo->forks[index] = 0;
//     ft_put_status(philo->t_start, philo->i_philo, 'f');
// }
