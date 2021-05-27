/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:18:01 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/25 10:27:07 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	negative;

	i = 0;
	result = 0;
	negative = 1;
	while (str[i] != '\0')
	{
		while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		{
			i++;
		}
		if (str[i] == '-')
		{
			negative = -1;
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		break;
	}
	return (result * negative);
}
