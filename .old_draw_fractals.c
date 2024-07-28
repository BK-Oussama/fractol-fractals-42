/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_draw_fractals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:07:58 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 03:08:40 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





// void	draw_mandelbrot(t_mlx *fractal)
// {
// 	t_point z;
// 	t_point c;
// 	int k;
	
// 	fractal->x = 0;
// 	while (fractal->x < WIDTH)
// 	{
// 		fractal->y = 0;
// 		while (fractal->y < HEIGHT)
// 		{
// 			z.x = 0;
// 			z.y = 0;
// 			c.x = scale(fractal->x, WIDTH, -2, 2) * fractal->zoom + fractal->move_x;
// 			c.y = scale(fractal->y, HEIGHT, 2, -2) * fractal->zoom + fractal->move_y;
// 			k = 0;
// 			while (k <= ITERATION)
// 			{
// 				z = sum_complex(complex_square(z), c);
// 				if (z.x * z.x + z.y * z.y > 4)
// 					break ;
// 				k++;
// 			}
// 			if (k == ITERATION)
// 				ft_put_pixel(fractal, 0x100626);
// 			else
// 				ft_put_pixel(fractal,  0x03346E * (k * 5));
// 			fractal->y++;
// 		}
// 		fractal->x++;
// 	}
// 	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0, 0);
// }





// void draw_julia(t_mlx *f, t_point xyPos)
// {
//     t_point z;
//     t_point c;
// 	int k;

// 	f->x = 0;
// 	z.x = 0;
// 	z.y = 0;
//     while (f->x < WIDTH)
//     {
//         f->y = 0;
//         while (f->y < HEIGHT)
//         {
//             z.x = scale(f->x, WIDTH, -2, 2) * f->zoom + f->move_x;
//             z.y = scale(f->y, HEIGHT, 2, -2) * f->zoom + f->move_y;
//             c.x = xyPos.x;
//             c.y = xyPos.y;
//             k = 0;
//             while (k <= ITERATION)
//             {
//                 z = sum_complex(complex_square(z), c);
//                 if (z.x * z.x + z.y * z.y >= 4)
//                     break;
//                 k++;
//             }
//             if (k == 0)
//                 ft_put_pixel(f, 00000);
// 			else
//                 ft_put_pixel(f, 0x03346E * (k * 5));
//             f->y++;
//         }
//         f->x++;
//     }
//     mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
// }












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