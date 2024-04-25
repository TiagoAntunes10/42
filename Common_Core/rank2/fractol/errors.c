/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:50:01 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/25 15:09:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Finish handle_errors function with the necessary closes and frees
void	handle_errors(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->window != 0)
			mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_display(mlx->mlx);
		free(mlx);
	}
	exit(1);
}

void	show_options(int argc)
{
	if (argc < 2)
	{
		ft_printf("Select options\n");
		ft_printf("julia or -j\nmandelbrot or -m\n");
		ft_printf("You can also modify the mandelbrot set or the Julia set ");
		ft_printf("by giving:");
		ft_printf("2 float values (first value real component");
		ft_printf(", second value imaginary component)\n");
		exit(1);
	}
	ft_printf("Invalid option\n");
	ft_printf("julia or -j\nmandelbrot or -m\n");
	ft_printf("You can also modify the mandelbrot set or the Julia set");
	ft_printf("by giving:");
	ft_printf("2 float values (first value real component");
	ft_printf(", second value imaginary component)\n");
	exit(1);
}
