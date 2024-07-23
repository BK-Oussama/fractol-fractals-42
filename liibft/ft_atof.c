/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou@student.42.fr <ouboukou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:54:51 by ouboukou@st       #+#    #+#             */
/*   Updated: 2024/07/23 19:18:55 by ouboukou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_atof(const char *str)
{

    double result = 0.0;
    double fraction = 0.0;
    int sign = 1;
    int divisor = 1;
    int decimal_count = 0;

    while (ft_isspace(*str))
        str++;

    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    
    while (*str)
    {
        if (ft_isdigit(*str))
        {
            if (decimal_count)
            {
                fraction = fraction * 10.0 + (*str - '0');
                divisor = divisor * 10;
            }
            else
                result = result * 10.0 + (*str - '0');
        }
        else if (*str == '.' && decimal_count == 0)
            decimal_count++;
        else
            break; // Stop processing on non-numeric character
    str++;
    }
    result = result + fraction / divisor;
    return (result * sign);
}
