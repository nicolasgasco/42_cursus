/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:15 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/22 19:18:35 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>

//  Printf
void	ft_putstr(const char *s, unsigned int *counter);
void	ft_putnbr(int n, unsigned int *counter);
void	ft_putunbr(unsigned int n, unsigned int *counter);
void	ft_puthex(unsigned int hex, char uppercase, unsigned int *counter);
void	ft_puthexp(unsigned long hex, unsigned int *counter);
int		ft_printf(const char *str, ...);

// Utils
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

// Scripts
int     ft_client(int argc, char *argv[]);
int		ft_server(void);
void	ft_put_bin(int n, int pid);

#endif