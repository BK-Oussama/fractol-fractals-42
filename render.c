/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:00:44 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/27 19:29:44 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "fractol.h"

void	render_fractals(t_mlx *f)
{
    if (ft_strncmp(f->set, "mandelbrot", 10) == 0)
	{
		t_point const_c;
		t_point var_z;
		draw_mandelbrot(f, &const_c, &var_z);
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
	}
	else
		printf("ZZZZZZZZZZZZZZZZZZZZZZZZ");
}
