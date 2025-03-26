/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ships.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:28:22 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 13:21:38 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	addition(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	draw_burning_ships(t_fractal *fractal)
{
	int		i;
	double	tmp;
	double	cx;
	double	cy;
	int		color;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	cx = ((fractal->x - WIDTH / 2) / fractal->zoom) + fractal->shift_x;
	cy = ((fractal->y - HEIGHT / 2) / fractal->zoom) + fractal->shift_y;
	while (++i < fractal->iterations)
	{
		tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + cx;
		fractal->zy = addition(2.0 * fractal->zx * fractal->zy) + cy;
		fractal->zx = addition(tmp);
		if (fractal->zx * fractal->zx
			+ fractal->zy * fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->iterations)
		color = 0x000000;
	else
		color = simple_color(i, fractal->iterations);
	put_color_to_pixel(fractal, color);
}
