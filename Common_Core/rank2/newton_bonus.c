/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:52:05 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 20:53:01 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fractol.h"
#include "Include/bonus.h"

static void	init_root(float *root_x, float *root_y)
{
	root_x[0] = 1;
	root_x[1] = -1.0 / 2;
	root_x[2] = -1.0 / 2;
	root_y[0] = 0;
	root_y[1] = sqrt(3) / 2;
	root_y[2] = -sqrt(3) / 2;
}

static int	check_root(long double x, long double y)
{
	float	tol;
	float	*root_x;
	float	*root_y;
	int		i;

	tol = 0.1;
	root_x = malloc(sizeof(float) * 3);
	root_y = malloc(sizeof(float) * 3);
	init_root(root_x, root_y);
	i = 0;
	while (i < 3)
	{
		if (fabsl(x - root_x[i]) <= tol && fabsl(y - root_y[i]) <= tol)
			return (1);
		i++;
	}
	free(root_x);
	free(root_y);
	return (0);
}

static void	check_set_newton(t_mlx *mlx, long double x, long double y)
{
	int			i;
	int			max_ite;
	int			colour;
	long double	temp;

	i = 0;
	max_ite = 100;
	while (check_root(x, y) == 0 && i < max_ite)
	{
		temp = x - ((pow(x, 3) + 3 * x * pow(y, 2) + mlx->c_real) / (3 * pow(x, 2) + 3 * pow(y, 2)));
		y = y - ((pow(y, 2) + 3 * pow(x, 2) + mlx->c_ima) / (6 * x));
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
