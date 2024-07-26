/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:00:44 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/26 17:09:55 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	print_fractal_options(void)
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

int main()
{
    print_fractal_options();
    return 0;

}
