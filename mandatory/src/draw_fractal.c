/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:59:58 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 13:15:37 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	simple_color(int i, int max_iter)
{
	int	r;
	int	g;
	int	b;
	int	color_value;

	color_value = (int)((double)i / max_iter * 255);
	r = (color_value * 2) % 256;
	g = (color_value * 5) % 256;
	b = (color_value * 10) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	put_color_to_pixel(t_fractal *fractal, int color)
{
	int	*buffer;

	buffer = fractal->pixel;
	buffer[((int)fractal->y * fractal->line / 4)
		+ (int)fractal->x] = color;
}

int	draw_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
				draw_mandelbrot(fractal);
			else if (!ft_strncmp(fractal->name, "julia", 5))
				draw_julia(fractal, fractal->parameters.x,
					fractal->parameters.y);
			else
				draw_burning_ships(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx_connect,
		fractal->mlx_window, fractal->img, 0, 0);
	return (0);
}
