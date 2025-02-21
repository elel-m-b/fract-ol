/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 13:20:58 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/20 18:31:02 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static	void	check_value(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
	{
		write(2, "Invalid number\n", 15);
		exit(1);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
		{
			write(2, "Invalid number\n", 15);
			exit(1);
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_puststr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	check_input(int ac, char **av, t_frcatol *fract)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		fract->name_fractal = av[1];
	else if (ac == 2 && ft_strcmp(av[1], "burning_ship") == 0)
		fract->name_fractal = av[1];
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		fract->name_fractal = av[1];
		check_value(av[2]);
		check_value(av[3]);
		fract->julia_r = ft_atof(av[2]);
		fract->julia_im = ft_atof(av[3]);
	}
	else
	{
		ft_puststr_fd(ERR_MSG, 2);
		exit(1);
	}
	fract_elem(fract);
}
