/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 19:21:54 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/20 18:29:06 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(int x, int y, t_frcatol *fract)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	c.imaginaire = convert_to_complex(y, HEIGHT, fract->start.imaginaire,
			fract->end.imaginaire) + fract->shift_y;
	c.reel = convert_to_complex(x, WIDTH, fract->start.reel,
			fract->end.reel) + fract->shift_x;
	z.imaginaire = 0;
	z.reel = 0;
	i = 0;
	while (i <= MAX_ITER)
	{
		z = sum_of(square(z), c);
		if ((z.imaginaire * z.imaginaire) + (z.reel * z.reel) > 4)
			break ;
		i++;
	}
	color = BLACK + ((i * 255) / MAX_ITER);
	my_put_pixel_to_color(x, y, color, &fract->img);
}

void	draw_julia(int x, int y, t_frcatol *fract, t_complex c)
{
	t_complex	z;
	int			i;
	int			color;

	z.imaginaire = convert_to_complex(y, HEIGHT, fract->start.imaginaire,
			fract->end.imaginaire);
	z.reel = convert_to_complex(x, WIDTH, fract->start.reel,
			fract->end.reel);
	i = 0;
	while (i <= MAX_ITER)
	{
		z = sum_of(square(z), c);
		if ((z.imaginaire * z.imaginaire) + (z.reel * z.reel) > 4)
			break ;
		i++;
	}
	color = BLACK + ((i * 255) / MAX_ITER);
	my_put_pixel_to_color(x, y, color, &fract->img);
}

// void	draw_burning_ship(int x, int y, t_frcatol *fract)
// {
// 	t_complex	c;
// 	t_complex	z;
// 	int		i;
// 	int		color;

// 	c.imaginaire = convert_to_complex(y, HEIGHT, fract->start.imaginaire,
// 			fract->end.imaginaire) + fract->shift_y;
// 	c.reel = convert_to_complex(x, WIDTH, fract->start.reel,
// 			fract->end.reel) + fract->shift_x;
// 	z.imaginaire = 0;
// 	z.reel = 0;
// 	i = 0;
// 	while (i < MAX_ITER)
// 	{
// 		double z_reel_abs = fabs(z.reel);
// 		double z_imag_abs = fabs(z.imaginaire);
// 		double new_reel = z_reel_abs * z_reel_abs - z_imag_abs * z_imag_abs + c.reel;
// 		double new_imag = 2 * z_reel_abs * z_imag_abs + c.imaginaire;
// 		z.reel = new_reel;
// 		z.imaginaire = new_imag;
// 		if ((z.reel * z.reel) + (z.imaginaire * z.imaginaire) > 4)
// 			break;
// 		i++;
// 	}
// 	color = BLACK + ((i * 255) / MAX_ITER);
// 	my_put_pixel_to_color(x, y, color, &fract->img);
// }
