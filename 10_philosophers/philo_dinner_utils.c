#include "philo.h"

void ft_start_dinner(t_philo *philo, unsigned int index)
{
	int				*fork_right;
	int				*fork_left;

	fork_right = &philo->common_data->forks[index];
	fork_left = &philo->common_data->forks[ft_get_i(philo, index - 1)];
	if (*fork_right == 1 && *fork_left == 1)
	{
		ft_die(philo);
		ft_eat(philo, index, fork_left, fork_right);
		sleep(philo->common_data->t_sleep);
	}
}

void	ft_eat(t_philo *philo, int index, int *fork_left, int *fork_right)
{
	pthread_mutex_lock(&philo->common_data->forks_mutex[index]);
	pthread_mutex_lock(&philo->common_data->forks_mutex[ft_get_i(philo, index - 1)]);
	*fork_right = 0;
	*fork_left = 0;
	ft_put_status(philo, 'e');
	philo->meals++;
	gettimeofday(&philo->t_meal, NULL);
	sleep(philo->common_data->t_eat);
	*fork_right = 1;
	*fork_left = 1;
	pthread_mutex_unlock(&philo->common_data->forks_mutex[index]);
	pthread_mutex_unlock(&philo->common_data->forks_mutex[ft_get_i(philo, index - 1)]);
}

void	ft_sleep(t_philo *philo)
{
}

void	ft_die(t_philo *philo)
{
	if (philo->meals == 0)
	{
		if (ft_calc_elapsed_time(ft_get_now(), philo->common_data->t_start) > philo->common_data->t_death * 1000) // Remove 1000
		{
			ft_put_status(philo, 'd');
			exit(1);
		}
	}
	else
	{
		if (ft_calc_elapsed_time(ft_get_now(), philo->t_meal) > philo->common_data->t_death * 1000) // Remove 1000
		{
			ft_put_status(philo, 'd');
			exit(1);
		}
	}
}

int    ft_get_i(t_philo *philo, int index)
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
