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

typedef struct Philo {
	unsigned int    n_philos;
    unsigned int    t_death;
    unsigned int    t_eat;
    unsigned int    t_sleep;
    unsigned int    n_eats;
}	philo;

// To be deleted
void    ft_print_struct(philo *philo);

// Put utils
void    ft_putstr(char *s);
int     ft_atoi(const char *str);

// Init utils
void	ft_init_struct(philo *philo, int argc, char *argv[]);

#endif