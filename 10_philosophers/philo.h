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
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	status_mutex;
}	t_data;

typedef struct p_data {
	int				i_philo;
	struct timeval	t_meal;
	int				meals;
	t_data			*c_data;
}	t_philo;

// Libft utils
void			ft_putstr(int fd, char *s);
int				ft_atoi(const char *str);
void			ft_putnbr(long n);

// To be deleted
void			ft_print_common(t_data *philo);
void			ft_print_philo(t_philo *philo);
void			ft_put_forks(int *forks);
void			ft_print_forks(t_philo *philo);

// Time utils
int				ft_calc_time_label(struct timeval start);

// Threads
void			ft_init_threads(t_data *c_data);
void			ft_create_threads(t_data *c_data, pthread_t *philos);
void			ft_join_threads(t_data *c_data, pthread_t *philos);
void			*ft_routine(void *vargp);

// Init utils
void			ft_init_common(t_data *philo, int argc, char *argv[]);
void			ft_init_philo(t_philo *philo, t_data *c_data, int i);
int				*ft_create_forks(int n_philos);
pthread_mutex_t	*ft_create_forks_mutex(int n_philos);

// Status utils
void			ft_put_status(t_philo *philo, char flag);
void			ft_put_action(t_philo *philo, char flag);
void			ft_put_timestamp(t_philo *philo);
int				ft_calc_time_label(struct timeval start);
void			ft_put_id(int id);

// Dinner utils
void			ft_start_dinner(t_philo *philo, unsigned int index);
int				ft_get_i(t_philo *philo, int index);
void			ft_sleep(t_philo *philo);
void			ft_eat(t_philo *philo, int index);
void			ft_think(t_philo *philo);
void			ft_death(t_philo *philo);
void			ft_free_c_data(t_data *c_data);
void			ft_free_philo(t_philo *philo);
void			ft_free_philos(pthread_t *philos);

// Time
int				ft_calc_timestamp(struct timeval start);
int				ft_calc_time(struct timeval now, struct timeval start);
struct timeval	ft_now(void);
void			ft_msleep(t_philo *philo, int interval);

#endif
