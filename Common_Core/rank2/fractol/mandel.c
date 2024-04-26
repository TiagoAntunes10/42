/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:59 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/26 08:50:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Check if there is an infinite loop
void	check_set(t_mlx *mlx, long double x, long double y)
{
	int			i;
	int			max_ite;
	int			colour;
	long double	r;
	long double	temp;
	
	i = 0;
	r = 2;
	max_ite = 500;
	while ((x * x + y * y) < r * r && i < max_ite)
	{
		temp = x * x - (y * y) + mlx->c_real + mlx->c_ima;
		y = 2 * x * y;
		x = temp;
		i++;
	}
	colour = colours(i % 8 * 32, i % 16 * 16, i % 32 * 8);
	if (errno == -1)
		handle_errors(mlx);
	if (colour != 0)
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, colour);
}

static int	mandel_render_start(t_mlx *mlx)
{
	long double	z_x;
	long double	z_y;

	z_x = - (mlx->win_length / 2 / mlx->zoom);
	mlx->x = 0;
	while (mlx->x < mlx->win_length)
	{
		z_y = - (mlx->win_height / 2 / mlx->zoom);
		mlx->y = 0;
		while (mlx->y < mlx->win_height)
		{
			check_set(mlx, z_x, z_y);
			z_y += 1 / mlx->zoom * 10;
			mlx->y++;
		}
		z_x += 1 / mlx->zoom * 10;
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}

void	mandel(char **argv, int argc)
{
	t_mlx	*mlx;
	
	mlx = open_window(argv, argc);
	mlx_loop_hook(mlx->mlx, &mandel_render_start, mlx);
	mlx_mouse_hook(mlx->window, &zoom_press, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
	if (mlx->window == NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}
