/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:17:35 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 18:17:32 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// this function calculate the next iteration of the formual rule : Zn = Zn-1^2
t_point	complex_square(t_point z)
{
	t_point	res;

	// the overall rule to get real part and imaginry part of a complex number:
	//
	// x^2 - y^2 			+				i (2xy);
	// to get real part  			to get imaginry part
	res.x = pow(z.x, 2) - pow(z.y, 2);
					//calculate sqrt of real part			#Real part: (x^2 - y^2)
	res.y = 2 * z.x * z.y;            
						// calculate imaginary part				#Imaginary part: 2xy
	return (res);
}

void	ft_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pxl = data->ptr_to_img + (y * data->size_line + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

// this function will calculate the sum of z  part that we alredy calcute using the complex sqrt with c and return (the results);
t_point	sum_complex(t_point z, t_point c)
{
	t_point	res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;
	return (res);
}
double	scale(double i, double max, double a, double b)
{
	return (i * (b - a) / max + a);
}

void	draw_mandelbrot(t_mlx *fractal)
{
	t_point z;
	t_point c;

	int i = 0;
	while (i < WIDTH)
	{
		int j = 0;
		while (j < HEIGHT)
		{
			z.x = 0;
			z.y = 0;
			c.x = scale(i, WIDTH, -2, 2);
			c.y = scale(j, HEIGHT, 2, -2);
			int iterations = 600;
			while (iterations)
			{
				z = sum_complex(complex_square(z), c);
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
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0, 0);
}


void draw_julia(t_mlx *fractal, t_point xyPos)
{
    t_point z;
    t_point c;

    int i = 0;
    while (i < WIDTH)
    {
        int j = 0;
        while (j < HEIGHT)
        {
            // Map each pixel to the complex plane
            z.x = scale(i, WIDTH, -2, 2);
            z.y = scale(j, HEIGHT, 2, -2);
            
            // Use the given constant complex number for Julia
            c.x = xyPos.x;
            c.y = xyPos.y;
            
            int iterations = 1000;
            while (iterations)
            {
                // Apply the Julia set formula: z = z^2 + c
                z = sum_complex(complex_square(z), c);

                // Check for divergence
                if (z.x * z.x + z.y * z.y > 4)
                    break;
                
                iterations--;
            }

            // Color the pixel based on whether it belongs to the Julia set
            if (iterations == 0)
                ft_put_pixel(fractal, i, j, 0x6F00FF); // Color for inside the set
            else
                ft_put_pixel(fractal, i, j, 0xF17102 * (iterations * 5)); // Gradient for outside the set
            
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img, 0, 0);
}
