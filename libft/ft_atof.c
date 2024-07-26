/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:54:51 by ouboukou@st       #+#    #+#             */
/*   Updated: 2024/07/26 14:10:26 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*space_and_sign(const char *str, int *sign)
{
	while (*str && ft_isspace(*str) == 0)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -(*sign);
		str++;
	}
	return ((char *)str);
}

double	ft_atof(const char *str)
{
	long	integer;
	double	fraction;
	double	power;
	int		sign;
    char    *new_str;

	integer = 0;
	fraction = 0;
	sign = 1;
	power = 1;
    new_str = space_and_sign(str, &sign);
	while (*new_str >= '0' && *new_str <= '9')
		integer = (integer * 10) + (*new_str++ - 48);
	if ('.' == *new_str)
		new_str++;
	while (*new_str && (*new_str >= '0' && *new_str <= '9'))
	{
		power = power / 10;
		fraction = fraction + (*new_str++ - 48) * power;
	}
	return ((integer + fraction) * sign);
}
