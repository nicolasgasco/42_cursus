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
# include <semaphore.h>
# include <fcntl.h>

// Structure with general data
typedef struct Philo {
	int				n_philos;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				n_eats;
	struct timeval	t_start;
	int				finished_init;
	int				finished_eating;
	int				end;
	int				*pids;
	sem_t			*forks_sem;
	sem_t			*death_sem;
}	t_data;

// Structure with data relevant to single philosophers + general data
typedef struct p_data {
	int				i_philo;
	struct timeval	t_meal;
	int				meals;
	pthread_t		death_check;
	t_data			*c_data;
}	t_philo;


// TBD
void			ft_put_pids(t_data *c_data);

// Structs initialization
void			ft_init_common(t_data *philo, int argc, char *argv[]);
void			ft_init_philo(t_philo *philo, t_data *c_data, int i);
void			ft_add_pid(t_data *c_data, int pid, int i);

// Error management
int				ft_common_error(t_data *c_data, int argc);

// Threads initialization
void			ft_create_procs(t_data *c_data);
void			ft_routine(t_philo *philo);
void			ft_multiple_philos(t_philo *philo);

// Time methods
int				ft_calc_timestamp(struct timeval start);
int				ft_calc_time(struct timeval now, struct timeval start);
struct timeval	ft_now(void);
void			ft_msleep(t_philo *philo, int interval);

// Free
void			ft_free_philo(t_philo *philo);
void			ft_free_philos(pthread_t *philos);

// Actions methods
void			ft_eat_sleep_think(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_death(t_philo *philo);
int				ft_get_i(t_philo *philo, int index);

// Output status to console
void			ft_put_status(t_philo *philo, char flag);
void			ft_put_death(t_philo *philo);

// Time methods
int				ft_calc_timestamp(struct timeval start);
int				ft_calc_time(struct timeval now, struct timeval start);
struct timeval	ft_now(void);
void			ft_msleep(t_philo *philo, int interval);

// Libft utils
void			ft_putstr(int fd, char *s);
int				ft_atoi(const char *str);
int				ft_strlen(const char *s);

#endif
