/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-16 10:59:43 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/20 21:53:42 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define DRACTOL_H
# include "/usr/include/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# define BONUS 1
# include <X11/keysym.h>
# include <math.h>
# define ERR_MSG "Usage: ./fractol mandelbrot OR ./fractol julia <real> <imaginary>\n"
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define BLACK      0x000000 

typedef struct s_complex
{
	double	imaginaire;
	double	reel;
}t_complex;

typedef	struct	s_img
{
	void	*img;
	int	bits_pixel;
	int	size_line;
	int	endian;
	char	*data_ptr;
}t_img;

typedef	struct	s_fractol
{
	void	*mlx;
	void	*win;
	char	*name_fractal;
	double	zoom;
	double	shift_x;
	double	shift_y;
	t_complex	start;
	t_complex	end;
	double	julia_r;
	double	julia_im;
	t_img img;
}t_frcatol;

int	ft_atoi(const char      *str);
int	ft_strcmp(char *s1, char *s2);
double	ft_atof(char *str);
double	convert_to_complex(int pixel_coord, double screen_max, double complex_min, double complex_max);
void	draw_julia(int x, int y, t_frcatol *fract, t_complex c);
void	events_init(t_frcatol *fract);
void	draw_mandelbrot(int x, int y, t_frcatol *fract);
void	fract_elem(t_frcatol *fract);
void	ft_puststr_fd(char *s, int fd);
void	check_input(int ac, char **av, t_frcatol *fract);
void	fract_render(t_frcatol *fract);
void	my_put_pixel_to_color(int x, int y, int color, t_img *img);
//void draw_burning_ship(int x, int y, t_frcatol *fract);
t_complex	sum_of(t_complex num1, t_complex num2);
t_complex	square(t_complex c);
#endif
