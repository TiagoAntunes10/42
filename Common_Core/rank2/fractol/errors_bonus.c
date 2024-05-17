/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:50:01 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/16 15:02:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

void	handle_errors(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->img != NULL)
			mlx_destroy_image(mlx->mlx, mlx->img);
		if (mlx->window != NULL)
			mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free(mlx);
	}
	exit(1);
}

void	show_options(int argc)
{
	if (argc < 2)
	{
		ft_printf("Select one option:\n");
		ft_printf("1 - julia or -j\n2 - mandelbrot or -m\n");
		ft_printf("3 - newton or -n\n");
		ft_printf("Modify the Julia and Newton sets with up to 2 floats");
		exit(1);
	}
	else if (argc > 4)
	{
		ft_printf("Too many arguments\n\n");
		ft_printf("Select one option:\n");
		ft_printf("1 - julia or -j\n2 - mandelbrot or -m\n");
		ft_printf("3 - newton or -n\n");
		ft_printf("Modify the Julia and Newton sets with up to 2 floats");
		exit(1);
	}
	ft_printf("Invalid option\n\n");
	ft_printf("Select one option:\n");
	ft_printf("1 - julia or -j\n2 - mandelbrot or -m\n");
	ft_printf("3 - newton or -n\n");
	ft_printf("Modify the Julia and Newton sets with up to 2 floats");
	exit(1);
}
