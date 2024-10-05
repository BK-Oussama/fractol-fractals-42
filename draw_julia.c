/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:10:37 by ouboukou          #+#    #+#             */
/*   Updated: 2024/10/05 17:41:26 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_julia_iterations(t_point z, t_point c)
{
	int	k;

	k = 0;
	while (k < ITERATION)
	{
		z = sum_complex(complex_square(z), c);
		if (z.x * z.x + z.y * z.y >= 4)
			break ;
		k++;
	}
	return (k);
}

void	draw_julia_pixel(t_mlx *f, t_point xyPos)
{
	t_point	z;
	t_point	c;
	int		k;

	z.x = scale(f->x, WIDTH, 2, -2) * f->zoom + f->move_x;
	z.y = scale(f->y, HEIGHT, -2, 2) * f->zoom + f->move_y;
	c.x = xyPos.x;
	c.y = xyPos.y;
	k = calculate_julia_iterations(z, c);
	if (k == 0)
		ft_put_pixel(f, 0x000000);
	else
		ft_put_pixel(f, get_color(k, ITERATION));
}

void	draw_julia(t_mlx *f, t_point xyPos)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			draw_julia_pixel(f, xyPos);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
}
