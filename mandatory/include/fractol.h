/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:07:41 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/03 12:37:28 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../mlx/mlx.h" //manejo de graficos con MiniLibX
# include "../libft/libft.h" 
# include <math.h>//funciones matematicas.
# include <X11/X.h> //X11 funcciones.
# include <X11/keysym.h> //para identificar eventos de teclado.
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdbool.h>
//dimensiones de la ventana
# define WIDTH	800
# define HEIGHT	800

typedef struct s_julia
{
	double	x;// parte real
	double	y;// parte imaginaria
}			t_julia;

typedef struct s_fractal//contiene la info de cada fractal.
{
	char		*name;//USADO nombre del fractal(julia o mandelbrot)
	void		*mlx_connect;// conexion con MLX.
	void		*mlx_window;//ventana MLX.
	void		*img;
	void		*pixel; //guardamos la direccion de la imagen = pixel
	int			iterations;// num de iteraciones para el fractal
	double		x;
	double		y;
	int			color;
	int			bbp; //bits x pixel (de la imagen)
	int			line; // tamanio de la linea (imagen)
	int			endian;
	double		zx;
	double		zy;
	double		shift_x;//movimientos en x para centrar mejor la imagen.
	double		shift_y;//movimientos en y.
	double		zoom;//nivel de zoom.
	t_julia		parameters;
}			t_fractal;

int		main(int argc, char **argv);
//inicializar: init.c
void	fractal_init(t_fractal *fractal);
void	mlx_initi(t_fractal *fractal);
//mouse, keyboard: events.c
void	events_init(t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		key_handler(int button, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
void	iterations_def(int button, t_fractal *fractal);
//draw_fractal.c + draw_otros
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal, double cx, double cy);
void	draw_burning_ships(t_fractal *fractal);
void	put_color_to_pixel(t_fractal *fractal, int color);
int		simple_color(int i, int max_iter);
int		draw_fractal(t_fractal *fractal);
//utils.c
void	malloc_error(void);
double	atodbl(char *str);

#endif
