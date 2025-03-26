/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:24:02 by xviladri          #+#    #+#             */
/*   Updated: 2025/02/28 18:40:39 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_julia(t_fractal *fractal, double cy, double cx)
{
	int		i;
	double	tmp;
	int		color;

	i = 0;
	fractal->zx = ((fractal->x - WIDTH / 2.0) / fractal->zoom)
		+ fractal->shift_x;
	fractal->zy = ((fractal->y - HEIGHT / 2.0) / fractal->zoom)
		+ fractal->shift_y;
	while (i < fractal->iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + cx;
		fractal->zy = 2.0 * tmp * fractal->zy + cy;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
		i++;
	}
	if (i == fractal->iterations)
		color = 0x000000;
	else
		color = simple_color(i, fractal->iterations);
	put_color_to_pixel(fractal, color);
}
