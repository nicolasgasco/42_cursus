#include "philo.h"

void ft_start_eating(t_philo *philo, unsigned int index)
{
	// printf("Philosopher %d is trying to eat\n", index);
	ft_take_forks(philo);
	sleep(1);
}

void	ft_take_forks(t_philo *philo)
{
	unsigned int	index;
	int				*fork_right;
	int				*fork_left;

	index = philo->i_philo;
	fork_right = &philo->common_data->forks[index];
	fork_left = &philo->common_data->forks[ft_calc_i(philo, index - 1)];
	// printf("Philosopher %u is before mutex\n", index);
	if (*fork_right == 1 && *fork_left == 1)
	{
		pthread_mutex_lock(&philo->common_data->forks_mutex[index]);
		pthread_mutex_lock(&philo->common_data->forks_mutex[ft_calc_i(philo, index - 1)]);
		// printf("Philosopher %u is inside mutex\n", index);
		// ft_print_forks(philo);
		*fork_right = 0;
		*fork_left = 0;
		// ft_print_forks(philo);
		int i = 0;
		while (i < 5)
		{
			printf("Philosopher %u is using forks (%d/5)\n", index, i + 1);
			ft_print_forks(philo);
			sleep(3);
			i++;
		}
		*fork_right = 1;
		*fork_left = 1;
		// ft_print_forks(philo);
		// printf("Philosopher %u is done taking forks\n", index);
		pthread_mutex_unlock(&philo->common_data->forks_mutex[index]);
		pthread_mutex_unlock(&philo->common_data->forks_mutex[ft_calc_i(philo, index - 1)]);
	}
	// printf("Philosopher %u is after mutex\n", index);
}

pthread_mutex_t *ft_create_forks_mutex(int n_philos, t_data *common_data)
{
	pthread_mutex_t *result;

	result = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_philos);
	return (result);
}

int    ft_calc_i(t_philo *philo, int index)
{
	int	fork_index;

    if (index < 0)
        fork_index = index + philo->common_data->n_philos;
    else if (index >= philo->common_data->n_philos)
		fork_index = index - philo->common_data->n_philos;
    else
		fork_index = index;
	return (fork_index);
}

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
