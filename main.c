/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:33:51 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/25 23:19:51 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// this function calculate the next iteration of the formual rule : Zn = Zn-1^2 + c
t_point complex_sqrt(t_point z)
{
	// the overall rule to get real part and imaginry part of a complex number:
		// 
		// x^2 - y^2 			+	 		i (2xy);
		// to get real part  			to get imaginry part
	
	t_point res;
	res.x = pow(z.x, 2) - pow(z.y, 2); 	//calculate sqrt of real part
	res.y = 2 * z.x * z.y; 				// calculate sart of imaginary part
	return (res);
}
void ft_put_pixel(t_mlx *data, int x, int y, int color)
{
    char *pxl;
    
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        pxl = data->ptr_to_img + (y * data->size_line + x * (data->bits_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

// this function will calculate the sum of z  part that we alredy calcute using the complex sqrt with c and return the results;
t_point sum_complex(t_point z, t_point c)
{
	t_point res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;

	return (res);
}
double scale(double i, double max, double a, double b)
{
	return (i * (b - a) / max + a);
}

void draw_mandelbrot(t_mlx *fractal)
{
	t_point z;
	t_point c;
	
	int i = 0;
	while (i <= WIDTH)
	{
		int j = 0;
		while(j <= HEIGHT)
		{	
			z.x = 0;
			z.y = 0;
			c.x = scale(i, WIDTH, -2 , 2);
			c.y = scale(j, HEIGHT, 2, -2);
			int	iterations = 600;
			while (iterations)
			{
				z = sum_complex(complex_sqrt(z), c);
				if (z.x * z.x + z.y * z.y > 4)
					break ;
				iterations--;
			}
			if (iterations == 0)
				ft_put_pixel(fractal, i, j, 0x6F00FF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0 , 0);	
}

// void draw_circle(t_mlx *data, int color)
// {
// 	int center_x = WIDTH / 2;
// 	int center_y = WIDTH / 2;
// 	int x, y;
// 	int raduis = 150;
// 	int circle_diameter = sqaure(raduis);
	
// 	x = center_x - raduis;
// 	while (x <= center_x + raduis)
// 	{
// 		y = center_y - raduis;
// 		while (y <= center_y + raduis)
// 		{
// 			if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= circle_diameter)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}	
// }

void color_screen(t_mlx *data, int color)
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0 , 0);
}

void intilize_mlx(t_mlx *mlx)
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
	mlx->ptr_to_img = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	if (mlx->ptr_to_img == NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
}

int clean_mlx_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(EXIT_SUCCESS);
	return 0;
}

int keyboard_events(int keycode, t_mlx *inf)
{
	if (keycode == XK_Escape)
		clean_mlx_exit(inf);
	else if (keycode == XK_Up)
		color_screen(inf, 0xFF4897d9);
	
	// else if (keycode == XK_Down)
	// else if (keycode == XK_Right)
	// else if (keycode == XK_Left )
	// else if (keycode == XK_KP_Add)
		// printf("here we are!!\n");
	else if (keycode == XK_KP_Subtract)
		draw_mandelbrot(inf);
		// printf("zzzzzzzzzzzzzzzzzzz\n");
		// draw_circle(inf, 0xd4e2f);
	return (0);
}






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
	// int j;
	// j = 0;
	// if (argc == 2)
	// {
		// while (argv[1][j])
		// {
			// argv[1][j] = ft_tolower(argv[1][j]);
			// j++;
		// }
		// if (ft_strncmp("julia", argv[1], 5) == 0)
			// intilize_mandelbrot();
	// }
	// else if (argc == 4)
	// {
		// while (argv[1][j])
		// {
			// argv[1][j] = ft_tolower(argv[1][j]);
			// j++;
		// }
		// if (ft_strncmp("julia", argv[1], 5) == 0)
			// intilize_julia(argv, );
	// }
	// else
		// ft_error("Please enter valid fractal sets");
// }


int mouse_events(int button, int x, int y, t_mlx *mlx)
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
		ft_error("Please enter a valid fracatl set");
	
	// parse_arguments(argc, argv);
	t_mlx inf;

	intilize_mlx(&inf);
	draw_mandelbrot(&inf);
		mlx_key_hook(inf.win_ptr, keyboard_events, &inf);
		mlx_mouse_hook(inf.win_ptr, mouse_events, &inf);
		mlx_hook(inf.win_ptr, DestroyNotify, 0, clean_mlx_exit, &inf);
	mlx_loop(inf.mlx_ptr);

	return 0;
}
