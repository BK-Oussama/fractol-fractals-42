/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 02:51:53 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_float(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (1);
	while (ft_isspace(str[i]) == 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

void	parse_julia_args(char **argv, t_mlx *f)
{

	if ((is_valid_float(argv[2]) == 1) || (is_valid_float(argv[3]) == 1))
	{
		fractals_guide();		
		clean_mlx_exit(f);
	}
	f->julia_xy.x = ft_atof(argv[2]);
	f->julia_xy.y = ft_atof(argv[3]);
	if (f->julia_xy.x >= -2 && f->julia_xy.x <= 2 && f->julia_xy.y >= -2 && f->julia_xy.y <= 2)
	{
		initialize_mlx(f);
		draw_julia(f, f->julia_xy);
	}

	else
	{
		fractals_guide();
		clean_mlx_exit(f);
	}

}


void	parse_arguments(int argc, char **argv, t_mlx *fractal)
{
	int j;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][j])
		{
			argv[1][j] = ft_tolower(argv[1][j]);
			j++;
		}
		if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
		{
			fractal->set = "mandelbrot";
			initialize_mlx(fractal);
			draw_mandelbrot(fractal);
		}
		else
		{
			fractals_guide();
			clean_mlx_exit(fractal);
		}
	}

	else if (argc == 4)
	{
		while (argv[1][j])
		{
			argv[1][j] = ft_tolower(argv[1][j]);
			j++;
		}
		if (ft_strncmp("julia", argv[1], 5) == 0)
		{
			fractal->set = "julia";
			parse_julia_args(argv, fractal);
		}
		else
			fractals_guide();
	}
	else
	{
		fractals_guide();
		clean_mlx_exit(fractal);
	}
}














void	fractals_guide(void)
{
	ft_putstr_fd("\n===========================  Available Fractals  ===========================\n", 1);
	ft_putstr_fd("Which fractal would you like to view?\n", 1);
	ft_putstr_fd("\t 1 - Mandelbrot\n", 1);
	ft_putstr_fd("\t 2 - Julia\n", 1);
	ft_putstr_fd("\n\e[36mUsage example:\t./fractol <type>\n\t\t./fractol Mandelbrot\e[0m", 1);
	ft_putstr_fd("\n\nFor Julia, you may specify starting values for the initial fractal shape.\n", 1);
	ft_putstr_fd("Values must be between -2.0 and 2.0 and must contain a decimal point.\n", 1);
	ft_putstr_fd("\n\e[36mUsage example:\t", 1);
	ft_putstr_fd("./fractol Julia\t 0.285 0.01\e[0m\n\n", 1);
}