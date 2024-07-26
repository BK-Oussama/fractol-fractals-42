/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:15 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 16:45:10 by ouboukou         ###   ########.fr       */
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
		ft_error("yyyyyyyyyyyyyyyyyyyyyyyyy");
	//  || (is_valid_float(argv[3]) == 1))
	xyPos.x = ft_atof(argv[2]);
	xyPos.y = ft_atof(argv[3]);
	if (xyPos.x >= -2 && xyPos.x <= 2 && xyPos.y >= -2 && xyPos.y <= 2)
		printf("kola\n");
	// draw_julia(fractal, xyPos);
	else
		ft_error("Please enter Valid julia set in the range of -2 and 2");
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
			ft_error("Destroy conections and what has been intilzie and exit prpoerly");
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