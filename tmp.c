/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:10:37 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 10:11:18 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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