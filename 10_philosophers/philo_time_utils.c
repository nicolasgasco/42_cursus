#include "philo.h"

int	ft_calc_time_label(struct timeval start)
{
	int				result;
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	result = (t_now.tv_sec - start.tv_sec) * 1000;
	result += (t_now.tv_usec - start.tv_usec) / 1000;
	return (result);
}

int	ft_calc_elapsed_time(struct timeval now, struct timeval start)
{
    int result;

    result = (now.tv_sec - start.tv_sec) * 1000;
	result += (now.tv_usec - start.tv_usec) / 1000;

    return (result);
}

struct timeval	ft_get_now()
{
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	return (t_now);	
}

void	ft_msleep(int interval)
{
	usleep(interval * 1000);
}