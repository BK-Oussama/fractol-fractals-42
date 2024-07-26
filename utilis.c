/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:25:30 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 16:08:13 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_mlx_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	initialize_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(EXIT_FAILURE);

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, "Fractol");
	if (mlx->win_ptr == NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(EXIT_FAILURE);
	}

	mlx->img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);
	if (mlx->img == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(EXIT_SUCCESS);
	}

	mlx->ptr_to_img = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (mlx->ptr_to_img == NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
}