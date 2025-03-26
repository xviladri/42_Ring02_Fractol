/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:15:43 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 16:03:40 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->iterations = 40;
}

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
}

void	mlx_initi(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (!fractal->mlx_connect)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connect,
			HEIGHT, WIDTH, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->pixel = mlx_get_data_addr(fractal->img,
			&fractal->bbp, &fractal->line, &fractal->endian);
	events_init(fractal);
}
