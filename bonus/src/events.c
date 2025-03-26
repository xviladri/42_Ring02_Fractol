/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:25:19 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 12:56:07 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->img);
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
	free(fractal->mlx_connect);
	free(fractal);
	exit(EXIT_SUCCESS);
}

void	iterations_def(int button, t_fractal *fractal)
{
	if (button == 109)
	{
		if (fractal->iterations < 4200)
			fractal->iterations += 20;
	}
	else
		if (fractal->iterations > 20)
			fractal->iterations -= 20;
}

int	key_handler(int button, t_fractal *fractal)
{
	if (button == 65307)
		close_handler(fractal);
	else if (button == 65361 || button == 97)
		fractal->shift_x -= 42 / fractal->zoom;
	else if (button == 65363 || button == 100)
		fractal->shift_x += 42 / fractal->zoom;
	else if (button == 65362 || button == 119)
		fractal->shift_y -= 42 / fractal->zoom;
	else if (button == 65364 || button == 115)
		fractal->shift_y += 42 / fractal->zoom;
	else if (button == 109 || button == 108)
		iterations_def(button, fractal);
	else
		return (0);
	draw_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_iter;
	double	scroll_x;
	double	scroll_y;

	zoom_iter = 1.42;
	scroll_x = (x - 800 / 2) / fractal->zoom + fractal->shift_x;
	scroll_y = (y - 800 / 2) / fractal->zoom + fractal->shift_y;
	if (button == 5)
		zoom_iter = 1.10;
	else if (button == 4)
		zoom_iter = 0.90;
	else
		return (0);
	fractal->zoom *= zoom_iter;
	fractal->shift_x = scroll_x - (x - WIDTH / 2) / fractal->zoom;
	fractal->shift_y = scroll_y - (y - HEIGHT / 2) / fractal->zoom;
	draw_fractal(fractal);
	return (0);
}
