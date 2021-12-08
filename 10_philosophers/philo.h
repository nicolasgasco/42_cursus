/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:01:54 by ngasco            #+#    #+#             */
/*   Updated: 2021/11/16 19:39:11 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct Philo {
	unsigned int    n_philos;
	unsigned int    t_death;
	unsigned int    t_eat;
	unsigned int    t_sleep;
	unsigned int    n_eats;
	struct timeval	t_start;
	int             *forks;
	pthread_mutex_t *forks_mutex;
	pthread_mutex_t	status_mutex;
}   t_data;

typedef struct p_data {
	unsigned int    i_philo;
	struct timeval	t_meal;
	int				meals;
	t_data          *common_data;
}   t_philo;


// Libft utils
void			ft_putstr(int fd, char *s);
int				ft_atoi(const char *str);
void			ft_putnbr(long n);

// To be deleted
void			ft_print_common(t_data *philo);
void			ft_print_philo(t_philo *philo);
void			ft_put_forks(int *forks);
void            ft_print_forks(t_philo *philo);

// Time utils
int				ft_calc_time_label(struct timeval start);

// Thread
void   			ft_init_threads(t_data *philo, int argc, char *argv[]);
void			ft_create_threads(t_data *common_data, pthread_t *philos);
void			ft_join_threads(t_data *common_data, pthread_t *philos);

// Init utils
void			ft_init_common(t_data *philo, int argc, char *argv[]);
void			ft_init_philo(t_philo *philo, t_data *common_data, int i);
int				*ft_create_forks(int n_philos);
pthread_mutex_t *ft_create_forks_mutex(int n_philos, t_data *common_data);

// Status utils
void			ft_put_status(t_philo *philo, char flag);
void			ft_put_action(char flag);
void			ft_put_timestamp(t_philo *philo);
int				ft_calc_time_label(struct timeval start);

// Dinner utils
void			ft_start_dinner(t_philo *philo, unsigned int index);
int				ft_get_i(t_philo *philo, int index);
void			ft_sleep(t_philo *philo);
void			ft_eat(t_philo *philo, int index, int *fork_left, int *fork_right);
void			ft_die(t_philo *philo);

// Time
int				ft_calc_time_label(struct timeval start);
int				ft_calc_elapsed_time(struct timeval now, struct timeval start);
struct timeval	ft_get_now();
void			ft_msleep(t_philo *philo, int interval);
#endif