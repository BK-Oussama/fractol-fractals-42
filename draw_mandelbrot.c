/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:17:35 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 05:07:49 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot_iterations(t_point c)
{
	t_point	z;
	int		k;

	z.x = 0;
	z.y = 0;
	k = 0;
	while (k <= ITERATION)
	{
		z = sum_complex(complex_square(z), c);
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		k++;
	}
	return (k);
}

void	draw_mandelbrot_pixel(t_mlx *fractal)
{
	t_point	c;
	int		k;

	c.x = scale(fractal->x, WIDTH, -2, 2) * fractal->zoom + fractal->move_x;
	c.y = scale(fractal->y, HEIGHT, 2, -2) * fractal->zoom + fractal->move_y;
	k = calculate_mandelbrot_iterations(c);
	if (k == ITERATION)
		ft_put_pixel(fractal, 0x100626);
	else
		ft_put_pixel(fractal, 0x03346E * (k * 5));
}

void	draw_mandelbrot(t_mlx *fractal)
{
	fractal->x = 0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			draw_mandelbrot_pixel(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0,
		0);
}
