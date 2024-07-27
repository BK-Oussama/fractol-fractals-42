/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:06 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/27 21:06:01 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
//  # include "mlx.h"
 # include <mlx.h>

# include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
# include <X11/X.h>

# define HEIGHT  700
# define WIDTH  700
# define ITERATION 100

typedef struct s_point
{
	double x;
	double y;
	
}	t_point;

typedef struct s_mlx
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	
	void	*img;
	void	*ptr_to_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	
	double zoom;
	char 	*set;
	int iter;
	int x;
	int y;
	t_point julia_xy;
	
}		t_mlx;



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

// Parsing Functions
int		is_valid_float(char *str);
void	parse_julia_args(char **argv, t_mlx *fractal);
void	parse_arguments(int argc, char **argv, t_mlx *fractal);

// Events Functions
int		keyboard_events(int keycode, t_mlx *inf);
int		mouse_events(int button, int x, int y, t_mlx *mlx);


// Main Functions

t_point complex_square(t_point z);
void ft_put_pixel(t_mlx *data, int x, int y, int color);
t_point sum_complex(t_point z, t_point c);
double scale(double i, double max, double a, double b);
void draw_mandelbrot(t_mlx *fractal);
void draw_julia(t_mlx *fractal, t_point xyPos);
void initialize_mlx(t_mlx *mlx);
int clean_mlx_exit(t_mlx *mlx);
void	fractals_guide(void);

#endif
