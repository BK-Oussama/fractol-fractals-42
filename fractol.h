/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:06 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/25 11:46:27 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
# include "mlx.h"
# include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
# include <X11/X.h>

# define HEIGHT  900
# define WIDTH  900

typedef struct mlx_s
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	
	void	*img;
	void	*ptr_to_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}		mlx_t;

typedef struct fractals_s
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
	
}	fractals_t;


#endif
