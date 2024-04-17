/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:48:16 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/06 17:41:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel_render_hook(t_mlx *mlx, int x, int y)
{
	float	z_x;
	float	z_y;

	z_x = - (mlx->win_length / 2 / mlx->zoom);
	mlx->x = 0;
	while (z_x * mlx->zoom <= mlx->win_length / 2)
	{
		z_y = - (mlx->win_height / 2 / mlx->zoom);
		mlx->y = 0;
		while (z_y * mlx->zoom <= mlx->win_height / 2)
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

// TODO: Check key codes and make a better zoom calculator
int	zoom_press(int keysym, t_mlx *mlx)
{
	if (keysym == 4)
		mlx->zoom *= 1.1;
	else if (keysym == 5)
		mlx->zoom *= 0.9;
	return (0);
}

int	keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx->window = NULL;
	}
	return (0);
}

int	xpress(int buttonsym, t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx->window = NULL;
	return (0);
}
