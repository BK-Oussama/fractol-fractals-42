/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:33:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/23 00:44:47 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include "fractol.h"

typedef struct mlx_s
{
	void 	*mlx_ptr;
	void 	*win_ptr;
}	mlx_t;


int hooking_function(int keycode, mlx_t *inf)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(inf->mlx_ptr, inf->win_ptr);
		mlx_destroy_display(inf->mlx_ptr);
		free(inf->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", keycode);
	return (0);
}

int main()
{
	mlx_t inf;

	inf.mlx_ptr = mlx_init();
	inf.win_ptr = mlx_new_window(inf.mlx_ptr, 950, 850, "Fractol Window");
	
	mlx_key_hook(inf.win_ptr, hooking_function, &inf);
	mlx_loop(inf.mlx_ptr);

	mlx_destroy_window(inf.mlx_ptr, inf.win_ptr);
	mlx_destroy_display(inf.mlx_ptr);
	free(inf.mlx_ptr);
	return 0;
}
