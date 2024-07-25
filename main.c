/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:33:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/25 13:30:36 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_put_pixel(mlx_t *data, int x, int y, int color)
{
    char *pxl;
    
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        pxl = data->ptr_to_img + (y * data->size_line + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}


void color_screen(mlx_t *data, int color)
{
	int y = 0;
	while (y < HEIGHT)
	{
		int x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

// void intilize_mlx(mlx_t *mlx)
// {
// 	mlx->mlx_ptr = mlx_init();
// 	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, height, width, "Fractol");
// 	mlx->img = mlx_new_image(mlx->mlx_ptr, height, width);
// 	mlx->ptr_to_img = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
// }

int clean_mlx_exit(mlx_t *mlx)
{
	// mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
	return 0;
}

int keyboard_events(int keycode, mlx_t *inf)
{
	if (keycode == XK_Escape)
		clean_mlx_exit(inf);
	else if (keycode == XK_Up)
		color_screen(inf, 0x4897d9);
	// else if (keycode == XK_Down)
	// else if (keycode == XK_Right)
	// else if (keycode == XK_Left )
	// else if (keycode == XK_KP_Add)
		// printf("here we are!!\n");
	else if (keycode == XK_KP_Subtract)
		color_screen(inf, 0xeeeeef);
		// printf("zzzzzzzzzzzzzzzzzzz\n");
	return (0);
}



// draw_mandelbrot(char **argv, t_list fractal)
// {
	
// }
// parse_julia_args(char **argv, t_list fractal)
// {
// 	if ((is_valid_float(argv[2]) == 1) || (is_valid_float(argv[3]) == 1))
// 		ft_error("Please enter Valid julia set in the range of -2 and 2");
	
// 	double x = ft_atof(argv[2]);
// 	double y = ft_atof(argv[3]);

// 	if (x < 2 || x > -2 || y < 2 || y > -2)
// 		ft_error("Please enter Valid julia set in the range of -2 and 2");
	
	

// }
// int is_valid_float(char *str)
// {
// 	while (ft_isspace(*str))
// 		str++;

// 	if (*str == '+' || *str == '-')
// 		str++;
// 	if (*str >= '0' && *str <= '9')
// 		return 0;
// 	else 
// 		return 1;
// }

// void parse_arguments(int argc, char **argv, t_list fractal)
// {
// 	int j;
// 	j = 0;
// 	if (argc == 2)
// 	{
// 		while (argv[1][j])
// 		{
// 			argv[1][j] = ft_tolower(argv[1][j]);
// 			j++;
// 		}
// 		if (ft_strncmp("julia", argv[1], 5) == 0)
// 			intilize_mandelbrot();
// 	}
// 	else if (argc == 4)
// 	{
// 		while (argv[1][j])
// 		{
// 			argv[1][j] = ft_tolower(argv[1][j]);
// 			j++;
// 		}
// 		if (ft_strncmp("julia", argv[1], 5) == 0)
// 			intilize_julia(argv, );
// 	}
// 	else
// 		ft_error("Please enter valid fractal sets");
// }

// int mouse_events(int keycode)
// {
// 	if (17 == keycode)
// 	{
// 		printf("sfjsdfjk");
// 		// clean_mlx_exit(inf);
// 	}
// 	return 0;
// }

int mouse_events(int button, int x, int y, mlx_t *mlx)
{
    printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);

    if (button == 1) // Left-click
        printf("Left-click action\n");
    else if (button == 2) // Right-click
        printf("Right-click action\n");
    else if (button == 3) // Middle-click
        printf("Middle-click action\n");
    else if (button == 4) // Scroll up
        printf("Scroll up action\n");
    else if (button == 5) // Scroll down
        printf("Scroll down action\n");

    return (0);
}
	
int main(int argc, char **argv)
{
		if (argc < 2)
		{
		ft_putendl_fd("Please enter a valid fracatl set", 2);
			return 0;
		}
	
	// parse_arguments(argc, argv);
	mlx_t inf;

	inf.mlx_ptr = mlx_init();
	inf.win_ptr = mlx_new_window(inf.mlx_ptr, WIDTH, HEIGHT, "Fractol-Window");
	
	inf.img = mlx_new_image(inf.mlx_ptr, WIDTH, HEIGHT);
	inf.ptr_to_img = mlx_get_data_addr(inf.img, &inf.bits_per_pixel, &inf.size_line, &inf.endian);
	
	mlx_key_hook(inf.win_ptr, keyboard_events, &inf);
	mlx_mouse_hook(inf.win_ptr, mouse_events, &inf);
    mlx_hook(inf.win_ptr, DestroyNotify, 0, clean_mlx_exit, &inf);

	mlx_loop(inf.mlx_ptr);

	return 0;
}
