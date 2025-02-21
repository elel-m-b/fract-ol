/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 21:34:34 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/02/21 10:56:24 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	zoom_follow_mouse(int x, int y, double zoom, t_frcatol *fract)
{
    double mouse_x;
    double mouse_y;
    
    if (ft_strcmp(fract->name_fractal, "julia") == 0)
    {
        mouse_x = convert_to_complex(y, WIDTH, fract->start.reel, fract->end.reel);
        mouse_y = convert_to_complex(x, HEIGHT, fract->start.imaginaire, fract->end.imaginaire);
    }
    else
    {
        mouse_x = convert_to_complex(x, WIDTH, fract->start.reel, fract->end.reel);
        mouse_y = convert_to_complex(y, HEIGHT, fract->start.imaginaire, fract->end.imaginaire);
    }
    
    fract->zoom *= zoom;
    fract->start.reel = (fract->start.reel - mouse_x) * zoom + mouse_x;
    fract->start.imaginaire = (fract->start.imaginaire - mouse_y) * zoom + mouse_y;
    fract->end.reel = (fract->end.reel - mouse_x) * zoom + mouse_x;
    fract->end.imaginaire = (fract->end.imaginaire - mouse_y) * zoom + mouse_y;
}

static void zoom_in_middle(double zoom, t_frcatol *fract)
{
    fract->start.reel *= zoom;
    fract->start.imaginaire *= zoom;
    fract->end.reel *= zoom;
    fract->end.imaginaire *= zoom;
}

static int mouse_handler(int button, int x, int y, t_frcatol *fract)
{
    double zoom;
    
    zoom = 1.0;
    if (button == 4 || button == 5)
    {
        if (button == 4)
        {
            fract->zoom = 0.1;
            zoom = 1 + fract->zoom;
        }
        else if (button == 5)
        {
            fract->zoom = 0.1;
            zoom = 1 - fract->zoom;
        }
        if (BONUS)
            zoom_follow_mouse(x, y, zoom, fract);
        else
            zoom_in_middle(zoom, fract);
        fract_render(fract);
    }
    return (0);
}

static int exit_handler(t_frcatol *fract)
{
    mlx_destroy_image(fract->mlx, fract->img.img);
    mlx_destroy_window(fract->mlx, fract->win);
    mlx_destroy_display(fract->mlx);
    free(fract->mlx);
    exit(1);
}

static int key_handler(int key, t_frcatol *fract)
{
    if (key == 65307)  // ESC
        exit_handler(fract);
    else if (key == 65361)  // Left arrow
        fract->shift_x += 0.02;
    else if (key == 65363)  // Right arrow
        fract->shift_x -= 0.02;
    else if (key == 65364)  // Down arrow
        fract->shift_y -= 0.02;
    else if (key == 65362)  // Up arrow
        fract->shift_y += 0.02;
    else if (key == 65293)  // Enter
        fract_elem(fract);
    fract_render(fract);
    return (0);
}

int mouse_motion_handler(int x, int y, t_frcatol *fract)
{
    if (ft_strcmp(fract->name_fractal, "julia") == 0)
    {
        fract->julia_r = convert_to_complex(x, WIDTH, fract->start.reel,
                fract->end.reel);
        fract->julia_im = convert_to_complex(y, HEIGHT, fract->start.imaginaire,
                fract->end.imaginaire);
        fract_render(fract);
    }
    return (0);
}

void events_init(t_frcatol *fract)
{
    mlx_hook(fract->win, KeyPress, KeyPressMask, key_handler, fract);
    mlx_hook(fract->win, DestroyNotify, NoEventMask, exit_handler, fract);
    mlx_hook(fract->win, 6, 1L << 6, mouse_motion_handler, fract);
    mlx_mouse_hook(fract->win, mouse_handler, fract);
}
