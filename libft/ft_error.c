/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:01:11 by ouboukou          #+#    #+#             */
/*   Updated: 2024/07/28 05:28:23 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_SUCCESS);
}
