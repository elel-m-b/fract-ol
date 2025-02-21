/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 13:21:12 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:28 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	convert_to_complex(int pixel_coord, double screen_max,
		double complex_min, double complex_max)
{
	return (complex_min + (pixel_coord / screen_max)
			* (complex_max - complex_min));
}

t_complex	sum_of(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.imaginaire = num1.imaginaire + num2.imaginaire;
	result.reel = num1.reel + num2.reel;
	return (result);
}

t_complex	square(t_complex c)
{
	t_complex	result;	

	result.reel = (c.reel * c.reel) - (c.imaginaire * c.imaginaire);
	result.imaginaire = 2 * c.reel * c.imaginaire;
	return (result);
}
