/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 18:10:45 by ouboukou         ###   ########.fr       */
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

void	parse_julia_args(char **argv, t_mlx *fractal)
{
	t_point	xyPos;

	if ((is_valid_float(argv[2]) == 1) || (is_valid_float(argv[3]) == 1))
	{
		fractals_guide();		
		clean_mlx_exit(fractal);
	}
	xyPos.x = ft_atof(argv[2]);
	xyPos.y = ft_atof(argv[3]);
	if (xyPos.x >= -2 && xyPos.x <= 2 && xyPos.y >= -2 && xyPos.y <= 2)
		draw_julia(fractal, xyPos);

		// printf("just cuse we need a statment here!\n");
	// draw_julia(fractal, xyPos);
	else
	{
		fractals_guide();
		clean_mlx_exit(fractal);
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
			draw_mandelbrot(fractal);
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
			parse_julia_args(argv, fractal);
		else
			ft_error("Destroy conections and what has been intilzie and exit prpoerly");
	}
	else
		ft_error("Please enter valid fractal sets");
}

void	fractals_guide(void)
{
	ft_putstr_fd("\n===========================  Available Fractals  ===========================\n", 1);
	ft_putstr_fd("Which fractal would you like to view?\n", 1);
	ft_putstr_fd("\t 1 - Mandelbrot\n", 1);
	ft_putstr_fd("\t 2 - Julia\n", 1);
	ft_putstr_fd("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol Mandelbrot\e[0m", 1);
	ft_putstr_fd("\n\nFor Julia, you may specify starting values for the initial fractal shape.\n", 1);
	ft_putstr_fd("Values must be between -2.0 and 2.0 and must contain a decimal point.\n", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putstr_fd("./fractol J\n\t\t./fractol Julia 0.285 0.01\e[0m\n\n", 1);
}