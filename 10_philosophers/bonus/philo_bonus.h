/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:03:02 by ngasco            #+#    #+#             */
/*   Updated: 2021/12/08 14:03:03 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/wait.h>


typedef struct Philo {
	int				n_philos;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				n_eats;
	struct timeval	t_start;
	int				*forks;
	int				finished_eating;
	int				end;
	pthread_mutex_t	d_mutex;
	pthread_mutex_t	e_mutex;
	pthread_mutex_t	*f_mutex;
	pthread_mutex_t	t_mutex;
	pthread_mutex_t	status_mutex;
}	t_data;

typedef struct p_data {
	int				i_philo;
	struct timeval	t_meal;
	int				meals;
	t_data			*c_data;
}	t_philo;

// Init
void			ft_init_common(t_data *philo, int argc, char *argv[]);
void			ft_init_philo(t_philo *philo, t_data *c_data, int i);
int				*ft_create_forks(int n_philos);
pthread_mutex_t	*ft_create_f_mutex(int n_philos);

// Error
int				ft_common_error(t_data *c_data, int argc);

// Threads
void			ft_init_threads(t_data *c_data);
void			ft_create_procs(t_data *c_data);
void			ft_join_threads(t_data *c_data, pthread_t *philos);
void			ft_routine(t_philo *philo);

// Time

int				ft_calc_timestamp(struct timeval start);
int				ft_calc_time(struct timeval now, struct timeval start);
int				ft_calc_time_micro(struct timeval now, struct timeval start);
struct timeval	ft_now(void);
void			ft_msleep(t_philo *philo, int interval);

// Free
void			ft_free_c_data(t_data *c_data);
void			ft_free_philo(t_philo *philo);
void			ft_free_philos(pthread_t *philos);

// Actions
void			ft_eat_sleep_think(t_philo *philo);
void			ft_death(t_philo *philo);
void			ft_eat(t_philo *philo, int *fork_l, int *fork_r);
int				ft_get_i(t_philo *philo, int index);

// Status
void			ft_put_forks(t_philo *philo);
void			ft_put_eat(t_philo *philo);
void			ft_put_sleep(t_philo *philo);
void			ft_put_think(t_philo *philo);
void			ft_put_death(t_philo *philo);

// Status utils
void			ft_put_timestamp(t_philo *philo);
int				ft_calc_time_label(struct timeval start);
void			ft_put_id(int id);

// Time
int				ft_calc_timestamp(struct timeval start);
int				ft_calc_time(struct timeval now, struct timeval start);
struct timeval	ft_now(void);
void			ft_msleep(t_philo *philo, int interval);

// Libft utils
void			ft_putstr(int fd, char *s);
int				ft_atoi(const char *str);
void			ft_putnbr(long n);

#endif