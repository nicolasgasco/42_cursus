/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsolinis <jsolinis@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:55:14 by jsolinis          #+#    #+#             */
/*   Updated: 2021/08/04 18:33:45 by jsolinis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	unsigned char	c_c;

	c_c = (unsigned char) c;
	if (c_c == '\t' || c_c == '\n' || c_c == '\v'
		|| c_c == '\f' || c_c == '\r' || c_c == ' ')
		return (1);
	return (0);
}

static int	ft_isneg(char c)
{
	if (c == '+')
		return (1);
	return (-1);
}

static int	ft_convert(char *s, int i, int sign, int num)
{
	while (s[i] != '\0')
	{
		if (s[i] == '+' || s[i] == '-')
		{
			sign = ft_isneg(s[i]);
			i++;
		}
		if (ft_isdigit(s[i]))
		{
			if (num > 214748365 && sign == -1)
				return (0);
			else if (num > 214748365 && sign == 1)
				return (-1);
			num = (num * 10) + (s[i] - '0');
			i++;
		}
		if (!(ft_isdigit(s[i])))
			break ;
	}
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		sign;
	int		num;

	s = (char *) str;
	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace((int) s[i]))
		i++;
	num = ft_convert(s, i, sign, num);
	return (num);
}
