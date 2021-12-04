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
}	t_data;

// Libft utils
void    ft_putstr(int fd, char *s);
int     ft_atoi(const char *str);
void	ft_putnbr(long n);

// To be deleted
void    ft_print_struct(t_data *philo);

// Time utils
int    ft_calc_elapsed_time(t_data *philo);

// Thread
void    ft_create_threads(t_data *philo, int argc, char *argv[]);

// Init utils
void	ft_init_struct(t_data *philo, int argc, char *argv[]);

// Status utils
void	ft_put_status(t_data *philo, int id, char flag);

#endif