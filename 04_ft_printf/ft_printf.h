/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:04:39 by ngasco            #+#    #+#             */
/*   Updated: 2021/08/26 12:15:52 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_puthex(unsigned long hex, char uppercase);
int		ft_printf(const char *, ...);

#endif
