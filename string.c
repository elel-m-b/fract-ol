/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 13:21:28 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/20 18:42:45 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(const char	*str)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	fraction = 1;
	result = 0;
	result = ft_atoi(str);
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			fraction *= 10;
			i++;
		}
	}
	return (sign * (result / fraction));
}
