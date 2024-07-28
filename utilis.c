/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:25:30 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 05:29:27 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_mlx_exit(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

void	initialize_mlx(t_mlx *mlx)
{
	mlx->zoom = 1.0;
	mlx->move_x = 0.0;
	mlx->move_y = 0.0;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		clean_mlx_exit(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, "Fractol");
	if (mlx->win_ptr == NULL)
		clean_mlx_exit(mlx);
	mlx->img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);
	if (mlx->img == NULL)
		clean_mlx_exit(mlx);
	mlx->ptr_to_img = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (mlx->ptr_to_img == NULL)
		clean_mlx_exit(mlx);
}
