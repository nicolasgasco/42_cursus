#include "philo.h"

int *ft_create_forks(int n_philos)
{
	int *result;
	int i;

	i = 0;
	result = (int *)malloc(sizeof(int) * n_philos + 1);
	while (i < n_philos)
	{
		result[i] = 1;
		i++;
	}
	result[i] = -1;
	return (result);
}

pthread_mutex_t *ft_create_forks_mutex(int n_philos, t_data *common_data)
{
	pthread_mutex_t *result;

	result = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philos);
	return (result);
}

void ft_start_eating(t_philo *philo, unsigned int index)
{
	int mutex_res;

	// printf("Philosopher %d is trying to eat\n", philo->i_philo);
	// mutex_res = pthread_mutex_lock(&philo->common_data->forks_mutex[philo->i_philo]);
	// if (mutex_res)
	// 	printf("Mutex failed!\n");
	ft_take_fork(philo, index);
	// ft_check_fork_index(philo, index - 1);
	// pthread_mutex_unlock(&philo->common_data->forks_mutex[philo->i_philo]);
}

// int ft_get_x_fork(t_philo *philo, int index)
// {
//     if (index < 0)
//         return (philo->forks[index + philo->n_philos]);
//     else if (index >= philo->n_philos)
//         return (philo->forks[index - philo->n_philos]);
//     return (philo->forks[index]);
// }

void	ft_take_fork(t_philo *philo, int index)
{
	pthread_mutex_lock(&philo->common_data->forks_mutex[index]);
	if (philo->common_data->forks[index] != 0)
		philo->common_data->forks[index] = 0;
	else
		printf("Mierda\n");
	pthread_mutex_unlock(&philo->common_data->forks_mutex[index]);
}

int    ft_check_fork_index(t_philo *philo, int index)
{
	int	fork_index;

    if (index < 0)
        fork_index = index + philo->common_data->n_philos;
    else if (index >= philo->common_data->n_philos)
		fork_index = index - philo->common_data->n_philos;
    else
		fork_index = index;
	return (fork_index);
    // ft_put_status(philo->common_data->t_start, philo->i_philo, 'f');
}
