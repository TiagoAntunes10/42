/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:48:16 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/15 21:30:16 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

int	zoom_press(int keysym, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (keysym == 4)
	{
		mlx->zoom *= 1.1;
		if (mlx->zoom_level % 3 == 0)
			mlx->c_real_beg += 0.05 / mlx->zoom;
		mlx->zoom_level++;
	}
	else if (mlx->zoom <= 1 && keysym == 5)
		return (0);
	else if (keysym == 5)
	{
		mlx->zoom_level--;
		mlx->zoom /= 1.1;
		if (mlx->zoom < 1)
			mlx->zoom = 1;
		if (mlx->zoom_level % 3 == 0)
			mlx->c_real_beg -= 0.05 / mlx->zoom;
	}
	mlx->c_real_end = 0.47 / mlx->zoom;
	return (0);
}

int	keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		handle_errors(mlx);
	return (0);
}

int	xpress(t_mlx *mlx)
{
	handle_errors(mlx);
	return (0);
}
