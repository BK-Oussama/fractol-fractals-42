/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:03 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 01:13:01 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_events(int keycode, t_mlx *f)
{
	if (keycode == XK_Escape)
		clean_mlx_exit(f);	
	else if (keycode == XK_Up)
		f->move_y = f->move_y + 0.2 * f->zoom;
	else if (keycode == XK_Down)
		f->move_y = f->move_y - 0.2 * f->zoom;
	else if (keycode == XK_Right)
		f->move_x = f->move_x + 0.2 * f->zoom;
	else if (keycode == XK_Left)
		f->move_x = f->move_x - 0.2 * f->zoom;
	else if (keycode == XK_KP_Add)
		f->zoom = f->zoom * 0.9;
	else if (keycode == XK_KP_Subtract)
		f->zoom = f->zoom / 0.9;

	// else if (keycode == XK_backslash)
		// ITERATION = ITERATION + 3;
	if (ft_strncmp(f->set, "mandelbrot", 10) == 0)
			draw_mandelbrot(f);
	else
			draw_julia(f, f->julia_xy);
	return (0);
}

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		mlx->zoom = mlx->zoom * 0.9;
		if (ft_strncmp(mlx->set, "mandelbrot", 10) == 0)
			draw_mandelbrot(mlx);
		else
			draw_julia(mlx, mlx->julia_xy);
	}
	else if (button == 5)
	{
		mlx->zoom = mlx->zoom / 0.9;
		if (ft_strncmp(mlx->set, "mandelbrot", 10) == 0)
			draw_mandelbrot(mlx);
		else
			draw_julia(mlx, mlx->julia_xy);
	}
	return (0);
}
