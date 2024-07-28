/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 05:26:56 by ouboukou         ###   ########.fr       */
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

int	parse_julia_args(char **argv, t_mlx *f)
{
	if ((is_valid_float(argv[2]) == 1) || (is_valid_float(argv[3]) == 1))
		fractals_guide();
	f->julia_xy.x = ft_atof(argv[2]);
	f->julia_xy.y = ft_atof(argv[3]);
	if (f->julia_xy.x >= -2 && f->julia_xy.x <= 2 && f->julia_xy.y >= -2
		&& f->julia_xy.y <= 2)
	{
		return (0);
	}
	else
		fractals_guide();
	return (1);
}

static void	to_lowercase(char *str)
{
	int	j;

	if (*str == '\0' || !str)
		fractals_guide();
	j = 0;
	while (str[j])
	{
		str[j] = ft_tolower(str[j]);
		j++;
	}
}

int	parse_arguments(int argc, char **argv, t_mlx *fractal)
{
	to_lowercase(argv[1]);
	if (argc == 2)
	{
		if (ft_strncmp("mandelbrot", argv[1], 10) == 0)
		{
			fractal->set = "mandelbrot";
			return (0);
		}
		else
			fractals_guide();
	}
	else if (argc == 4)
	{
		if (ft_strncmp("julia", argv[1], 5) == 0)
		{
			fractal->set = "julia";
			if (parse_julia_args(argv, fractal) == 0)
				return (0);
		}
		else
			fractals_guide();
	}
	else
		fractals_guide();
	return (1);
}

void	fractals_guide(void)
{
	ft_putstr_fd("\n===========================  Available Fractals  ==", 1);
	ft_putstr_fd("=========================\n\n", 1);
	ft_putstr_fd("Which fractal would you like to view?\n", 1);
	ft_putstr_fd("\t 1 - Mandelbrot\n", 1);
	ft_putstr_fd("\t 2 - Julia\n", 1);
	ft_putstr_fd("\n\e[36mUsage example:\t./fractol <type>\n\t\t./fractol", 1);
	ft_putstr_fd("Mandelbrot\e[0m", 1);
	ft_putstr_fd("\n\nFor Julia, you may specify starting values for the", 1);
	ft_putstr_fd("initial fractal shape.\n", 1);
	ft_putstr_fd("Values must be between -2.0 and 2.0 and must ", 1);
	ft_putstr_fd("contain a decimal point.\n", 1);
	ft_putstr_fd("\n\e[36mUsage example:\t", 1);
	ft_putstr_fd("./fractol Julia\t 0.285 0.01\e[0m\n\n", 1);
	exit(EXIT_FAILURE);
}
