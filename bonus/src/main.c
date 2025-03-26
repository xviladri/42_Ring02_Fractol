/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:39:45 by xviladri          #+#    #+#             */
/*   Updated: 2025/03/04 16:25:39 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	set_fractal(t_fractal *fractal)
{
	fractal_init(fractal);
	mlx_initi(fractal);
	draw_fractal(fractal);
	mlx_loop(fractal->mlx_connect);
}

static int	is_number(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (str[i] == '.' && dot == 0)
		{
			i++;
			dot++;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	julia_argv(t_fractal *fractal, char **argv)
{
	double	x;
	double	y;

	if (!argv[2] || !argv[3])
		exit(EXIT_FAILURE);
	fractal->name = argv[1];
	if (!is_number(argv[2]) || !is_number(argv[3]))
		exit(EXIT_FAILURE);
	x = atodbl(argv[2]);
	y = atodbl(argv[3]);
	if (x < -2 || x > 2 || y < -2 || y > 2)
		exit(EXIT_FAILURE);
	fractal->parameters.y = x;
	fractal->parameters.x = y;
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = NULL;
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		fractal->name = argv[1];
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
		julia_argv(fractal, argv);
	else if (argc == 3 && (!ft_strncmp(argv[1], "burning", 8)))
	{
		if (!ft_strncmp(argv[2], "ships", 6))
			fractal->name = "burning ships";
		else
			exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Invalid input\n");
		ft_printf("Available fractals: mandelbrot, julia or burning ships\n");
		exit(EXIT_FAILURE);
	}
	set_fractal(fractal);
	return (0);
}
