/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:32:26 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 13:22:20 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	malloc_error(void)
{
	ft_printf("Malloc error: ");
	exit(EXIT_FAILURE);
}

double	atodbl(char	*str)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\n'))
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		integral = (integral * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str)
	{
		power /= 10;
		fractional = fractional + (*str++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}
