/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:52:05 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/15 22:26:32 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fractol.h"
#include "Include/bonus.h"

static void	check_set_newton(t_mlx *mlx, long double x, long double y)
{
	int			i;
	int			max_ite;
	int			colour;
	long double	r;
	long double	temp;

	i = 0;
	r = 2;
	max_ite = 100;
	while ((x * x + y * y) < r * r && i < max_ite)
	{
		temp = pow(x, 3) + 3 * x * pow(y, 2) + mlx->c_real;
		y = pow(y, 3) + 3 * y * pow(x, 2) + mlx->c_ima;
		x = temp;
		i++;
	}
	colour = colours(i % 6 * 6, i % 7 * 4, i % 5 * 5);
	if (errno == -1)
		handle_errors(mlx);
	if (colour != 0)
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, colour);
}

static int	newton_render_start(t_mlx *mlx)
{
	long double	z_x;
	long double	z_y;

	mlx->x = 0;
	while (mlx->x < mlx->win_length)
	{
		z_x = (mlx->x * (3.5 / mlx->win_length) + mlx->c_real_beg + 0.2)
			/ mlx->zoom;
		mlx->y = 0;
		while (mlx->y < mlx->win_height)
		{
			z_y = (mlx->y * (3.5 / mlx->win_height) - 0.75 + mlx->c_ima_end)
				/ mlx->zoom;
			check_set_newton(mlx, z_x, z_y);
			mlx->y++;
		}
		mlx->x++;
	}
	if (mlx->window != NULL)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}

void	newton(char **argv, int argc)
{
	t_mlx	*mlx;

	mlx = open_window(argv, argc);
	mlx_loop_hook(mlx->mlx, &newton_render_start, mlx);
	mlx_mouse_hook(mlx->window, &zoom_press_bonus, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress_bonus, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
}
