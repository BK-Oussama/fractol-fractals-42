/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:33:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 05:09:29 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render(t_mlx *f)
{
	if (ft_strncmp(f->set, "mandelbrot", 10) == 0)
		draw_mandelbrot(f);
	else
		draw_julia(f, f->julia_xy);
}

int	main(int argc, char **argv)
{
	t_mlx	f;

	if (argc < 2)
	{
		fractals_guide();
		exit(EXIT_SUCCESS);
	}
	parse_arguments(argc, argv, &f);
	initialize_mlx(&f);
	ft_render(&f);
	mlx_key_hook(f.win_ptr, keyboard_events, &f);
	mlx_mouse_hook(f.win_ptr, mouse_events, &f);
	mlx_hook(f.win_ptr, DestroyNotify, 0, clean_mlx_exit, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
