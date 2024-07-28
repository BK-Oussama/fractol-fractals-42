/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utilis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:00:44 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/27 19:29:44 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	complex_square(t_point z)
{
	t_point	res;

	res.x = pow(z.x, 2) - pow(z.y, 2);
	res.y = 2 * z.x * z.y;            
	return (res);
}

void	ft_put_pixel(t_mlx *data, int color)
{
	char	*pxl;

		pxl = data->ptr_to_img + (data->y * data->size_line + data->x * (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
}

t_point	sum_complex(t_point z, t_point c)
{
	t_point	res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;
	return (res);
}

double	scale(double pxl_cord, double width, double plan_min, double plan_max)
{
	return (pxl_cord * (plan_max - plan_min) / width + plan_min);
}
