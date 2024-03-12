/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:41:43 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/18 21:14:25 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*open_window()
{
	t_mlx	*mlx;

	mlx = create_struct();
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		handle_errors(mlx);
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_length,
							  mlx->win_height, "Fract-ol");
	if (mlx->window == NULL)
		handle_errors(mlx);
	return (mlx);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
	*(int *)pixel = color;	
}

void	push_img(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_length, mlx->win_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
							   &mlx->line_lenght, &mlx->endian);
}
