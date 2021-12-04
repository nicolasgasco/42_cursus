#include "philo.h"

int    ft_calc_elapsed_time(t_data *philo)
{
	int			result;
	struct timeval	t_now;
	struct timeval 	t_now2;
	
	printf("\n\nMIERDAAAAA\n");
	gettimeofday(&t_now, NULL);
	usleep(50);
	gettimeofday(&t_now2, NULL);
	result = (t_now2.tv_sec - t_now.tv_sec) * 1000000;
	result += (t_now2.tv_usec - t_now.tv_usec);
	// result = (t_now.tv_sec - philo->t_start.tv_sec) * 1000000;
	// result += (t_now.tv_usec - philo->t_start.tv_usec);
	printf("Elapsed time is %d\n", result);
	return (result);
}