/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 13:21:20 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/20 18:39:25 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	fract_elem(t_frcatol *fract)
{
	fract->start.imaginaire = 2;
	fract->start.reel = -2;
	fract->end.reel = 2;
	fract->end.imaginaire = -2;
	fract->shift_x = 0;
	fract->shift_y = 0;
	fract->zoom = 0;
}

void	my_put_pixel_to_color(int x, int y, int color, t_img *img)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bits_pixel) / 8);
	*(int *)(img->data_ptr + offset) = color;
}

static	void	_check_pixel(int x, int y, t_frcatol *fract)
{
	t_complex	c;

	if (ft_strcmp(fract->name_fractal, "mandelbrot") == 0)
		draw_mandelbrot(x, y, fract);
	else if (ft_strcmp(fract->name_fractal, "julia") == 0)
	{
		c.reel = fract->julia_r;
		c.imaginaire = fract->julia_im;
		draw_julia(x, y, fract, c);
	}
	// else if (ft_strcmp(fract->name_fractal, "burning_ship") == 0)
	// 	draw_burning_ship(x, y, fract);
}

void	fract_render(t_frcatol *fract)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			_check_pixel(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.img, 0, 0);
}
