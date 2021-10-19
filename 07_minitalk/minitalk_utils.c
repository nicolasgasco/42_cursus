/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:50:12 by ngasco            #+#    #+#             */
/*   Updated: 2021/10/19 19:33:22 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;
	int				negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * negative);
}


void	ft_put_bin(int n, int pid, int *i)
{
	if (n <= 1)
	{
		if (n == 0)
			// ft_printf("%d\n", n);
			kill(pid, SIGUSR1);
		else if (n == 1)
			// ft_printf("%d\n", n);
			kill(pid, SIGUSR2);
		usleep(200);
		printf("I is %d\n", *i);
		while (*i != 8)
		{
			kill(pid, SIGUSR1);
			usleep(200);
			*i++;
		}
	}
	else
	{
		ft_put_bin(n / 2, pid, i);
		if ((n % 2) == 0)
			kill(pid, SIGUSR1);
		else if ((n % 2) == 1)
			kill(pid, SIGUSR2);
		*i++;
		usleep(200);
	}
}

void	ft_stobin(int n, int pid)
{
	int	i;

	i = 0;
	ft_put_bin(n, pid, &i);
}


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	while (i++ < len1)
		res[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len2)
		res[i - 1 + len1] = s2[i - 1];
	res[i - 1 + len1] = '\0';
	free((char *)s1);
	return (res);
}