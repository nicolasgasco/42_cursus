#include "philo.h"

int    ft_calc_elapsed_time(t_data *philo)
{
	int			result;
	struct timeval	t_now;
	struct timeval 	t_now2;
	
	gettimeofday(&t_now, NULL);
	usleep(5000);
	gettimeofday(&t_now2, NULL);
	result = (t_now2.tv_sec - t_now.tv_sec) * 1000;
	result += (t_now2.tv_usec - t_now.tv_usec) / 1000;
	return (result);
}

void	ft_put_status(t_data *philo, int id, int flag)
{
	int	timestamp;
	
	timestamp = ft_calc_elapsed_time(philo);
	if (flag == 'f')
		ft_putstr(1, " has taken a fork\n");
	else if (flag == 'e')
		ft_putstr(1, " is eating\n");
	else if (flag == 's')
		ft_putstr(1, " is sleeping\n");
	else if (flag == 't')
		ft_putstr(1, " is thinking\n");
	else if (flag == 'd')
		ft_putstr(1, " is thinking\n");
}