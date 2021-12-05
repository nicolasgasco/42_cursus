#include "philo.h"

double    ft_calc_elapsed_time(struct timeval start)
{
	double			result;
	struct timeval 	t_now;
	
	gettimeofday(&t_now, NULL);
	result = (t_now.tv_sec - start.tv_sec) * 1000.0;
	result += (t_now.tv_usec - start.tv_usec) / 1000.0;
	return (result);
}

void	ft_put_action(char flag)
{
	if (flag == 'f')
		ft_putstr(1, "has taken a fork\n");
	else if (flag == 'e')
		ft_putstr(1, "is eating\n");
	else if (flag == 's')
		ft_putstr(1, "is sleeping\n");
	else if (flag == 't')
		ft_putstr(1, "is thinking\n");
	else if (flag == 'd')
		ft_putstr(1, "is thinking\n");
}

void	ft_put_id(int id)
{
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, " ", 1);
}

void	ft_put_status(struct timeval start, int id, char flag)
{
	int	timestamp;
	
	timestamp = ft_calc_elapsed_time(start);
	ft_putnbr(timestamp);
	ft_put_id(id);
	ft_put_action(flag);
	ft_putstr(1, "\n\n");
}