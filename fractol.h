/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:06 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 18:38:18 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 700
# define WIDTH 700
# define ITERATION 256

typedef struct s_point
{
	double	x;
	double	y;

}			t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*img;
	void	*ptr_to_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	double	zoom;
	char	*set;
	int		iter;

	int		x;
	int		y;

	double	move_x;
	double	move_y;
	t_point	julia_xy;

}			t_mlx;

// Parsing Functions
int			parse_arguments(int argc, char **argv, t_mlx *fractal);
int			parse_julia_args(char **argv, t_mlx *fractal);
int			is_valid_float(char *str);

// Events Functions
int			keyboard_events(int keycode, t_mlx *inf);
int			mouse_events(int button, int x, int y, t_mlx *mlx);

// Main Functions

t_point		complex_square(t_point z);
t_point		sum_complex(t_point z, t_point c);

double		scale(double i, double max, double a, double b);
void		ft_put_pixel(t_mlx *data, int color);
int			get_color(int k, int max_iterations);

void		draw_mandelbrot(t_mlx *fractal);
int			calculate_mandelbrot_iterations(t_point c);
void		draw_mandelbrot_pixel(t_mlx *fractal);

void		draw_julia(t_mlx *fractal, t_point xyPos);
int			calculate_julia_iterations(t_point z, t_point c);
void		draw_julia_pixel(t_mlx *f, t_point xyPos);

void		initialize_mlx(t_mlx *mlx);
int			clean_mlx_exit(t_mlx *mlx);
void		fractals_guide(void);

#endif
