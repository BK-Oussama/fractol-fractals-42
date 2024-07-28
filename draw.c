/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:17:35 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 02:56:09 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	draw_mandelbrot(t_mlx *fractal)
{
	t_point z;
	t_point c;
	int k;
	
	fractal->x = 0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			z.x = 0;
			z.y = 0;
			c.x = scale(fractal->x, WIDTH, -2, 2) * fractal->zoom + fractal->move_x;
			c.y = scale(fractal->y, HEIGHT, 2, -2) * fractal->zoom + fractal->move_y;
			k = 0;
			while (k <= ITERATION)
			{
				z = sum_complex(complex_square(z), c);
				if (z.x * z.x + z.y * z.y > 4)
					break ;
				k++;
			}
			if (k == ITERATION)
				ft_put_pixel(fractal, 0x100626);
			else
				ft_put_pixel(fractal,  0x03346E * (k * 5));
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0, 0);
}

void draw_julia(t_mlx *f, t_point xyPos)
{
    t_point z;
    t_point c;
	int k;

	f->x = 0;
	z.x = 0;
	z.y = 0;
    while (f->x < WIDTH)
    {
        f->y = 0;
        while (f->y < HEIGHT)
        {
            z.x = scale(f->x, WIDTH, -2, 2) * f->zoom + f->move_x;
            z.y = scale(f->y, HEIGHT, 2, -2) * f->zoom + f->move_y;
            c.x = xyPos.x;
            c.y = xyPos.y;
            k = 0;
            while (k <= ITERATION)
            {
                z = sum_complex(complex_square(z), c);
                if (z.x * z.x + z.y * z.y >= 4)
                    break;
                k++;
            }
            if (k == 0)
                ft_put_pixel(f, 00000);
			else
                ft_put_pixel(f, 0x03346E * (k * 5));
            f->y++;
        }
        f->x++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
}
