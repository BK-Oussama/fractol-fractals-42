/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:33:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 15:11:49 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void draw_julia(t_mlx *fractal, t_point xyPos)
// {

// }

int	main(int argc, char **argv)
{
	t_mlx	inf;

	if (argc < 2)
		ft_error("Please enter a valid fracatl set");
	initialize_mlx(&inf);
	parse_arguments(argc, argv, &inf);
	// draw_mandelbrot(&inf);
	mlx_key_hook(inf.win_ptr, keyboard_events, &inf);
	mlx_mouse_hook(inf.win_ptr, mouse_events, &inf);
	mlx_hook(inf.win_ptr, DestroyNotify, 0, clean_mlx_exit, &inf);
	mlx_loop(inf.mlx_ptr);
	return (0);
}
