/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 16:42:15 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/21 10:48:42 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	initialize_fractal(t_frcatol *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
	{
		free(fract->mlx);
		exit(1);
	}
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name_fractal);
	if (!fract->win)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		exit(1);
	}
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		exit(1);
	}
	fract->img.data_ptr = mlx_get_data_addr(fract->img.img,
			&fract->img.bits_pixel, &fract->img.size_line, &fract->img.endian);
}

int	main(int ac, char **av)
{
	t_frcatol	fract;

	check_input(ac, av, &fract);
	initialize_fractal(&fract);
	fract_render(&fract);
	events_init(&fract);
	mlx_loop(fract.mlx);
	return (0);
}
