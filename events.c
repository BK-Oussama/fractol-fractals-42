/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:03 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 18:14:50 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard_events(int keycode, t_mlx *inf)
{
	if (keycode == XK_Escape)
		clean_mlx_exit(inf);
	else if (keycode == XK_Up)
		printf("saa");
		// draw_mandelbrot(inf);
	// else if (keycode == XK_Down)
	// else if (keycode == XK_Right)
	// else if (keycode == XK_Left )
	// else if (keycode == XK_KP_Add)
	// printf("here we are!!\n");
	else if (keycode == XK_KP_Subtract)
		printf("saa8888888888");
		// draw_mandelbrot(inf);
	// printf("zzzzzzzzzzzzzzzzzzz\n");
	// draw_circle(inf, 0xd4e2f);
	return (0);
}

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);

	if (button == 1) // Left-click
		draw_mandelbrot(mlx);
	else if (button == 2) // Right-click
		printf("Right-click action\n");
	else if (button == 3) // Middle-click
		printf("Middle-click action\n");
	else if (button == 4) // Scroll up
		printf("Scroll up action\n");
	else if (button == 5) // Scroll down
		printf("Scroll down action\n");

	return (0);
}