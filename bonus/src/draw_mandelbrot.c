/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:13:08 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 13:20:24 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	temp;
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
		temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + cy;
		fractal->zx = temp;
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
