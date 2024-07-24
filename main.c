/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:33:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/24 14:39:48 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/*
int keyboard_event(int keycode, mlx_t *inf)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(inf->mlx_ptr, inf->win_ptr);
		mlx_destroy_display(inf->mlx_ptr);
		free(inf->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	else if (keycode == )
	else if (keycode == )
	else if (keycode == )
	else if (keycode == )
	else if (keycode == )

	return (0);
}
*/

draw_mandelbrot(char **argv, t_list fractal)
{
	
}
parse_julia_args(char **argv, t_list fractal)
{
	if ((is_valid_float(argv[2]) == 1) || (is_valid_float(argv[3]) == 1))
		ft_error("Please enter Valid julia set in the range of -2 and 2");
	
	double x = ft_atof(argv[2]);
	double y = ft_atof(argv[3]);

	if (x > 2 || x < -2 || y > 2 || y < -2)
		ft_error("Please enter Valid julia set in the range of -2 and 2");
	
	

}
int is_valid_float(char *str)
{
	while (ft_isspace(*str))
		str++;

	if (*str == '+' || *str == '-')
		str++;
	if (*str >= '0' && *str <= '9')
		return 0;
	else 
		return 1;
}

void parse_arguments(int argc, char **argv, t_list fractal)
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
		if (ft_strncmp("julia", argv[1], 5) == 0)
			intilize_mandelbrot();
	}
	else if (argc == 4)
	{
		while (argv[1][j])
		{
			argv[1][j] = ft_tolower(argv[1][j]);
			j++;
		}
		if (ft_strncmp("julia", argv[1], 5) == 0)
			intilize_julia(argv, );
	}
	else
		ft_error("Please enter valid fractal sets");
}

int main(int argc, char **argv)
{

	if (argc < 2)
		ft_putendl_fd("Please enter a valid fracatl set", 2);
	

	parse_arguments(argc, argv);
	// mlx_t inf;

	//inf.mlx_ptr = mlx_init();
	//inf.win_ptr = mlx_new_window(inf.mlx_ptr, 950, 850, "Fractol Window");
	
	// mlx_key_hook(inf.win_ptr, hooking_function, &inf);
	// mlx_loop(inf.mlx_ptr);

	// mlx_destroy_window(inf.mlx_ptr, inf.win_ptr);
	// mlx_destroy_display(inf.mlx_ptr);
	// free(inf.mlx_ptr);
	return 0;
}

void intilize_mlx(mlx_t *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, height, width, "Fractol");
	mlx->img = mlx_new_image(mlx->mlx_ptr, height, width);
	mlx->ptr_to_img = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
}

void clean_mlx_exit(mlx_t *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
}



