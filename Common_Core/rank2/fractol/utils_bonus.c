/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:55:36 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/16 15:26:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fractol.h"
#include "Include/bonus.h"

static int	key_move(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_DOWN)
	{
		mlx->c_ima_beg -= 0.1 / mlx->zoom;
		mlx->c_ima_end -= 0.1 / mlx->zoom;
	}
	else if (keysym == KEY_UP)
	{
		mlx->c_ima_beg += 0.1 / mlx->zoom;
		mlx->c_ima_end += 0.1 / mlx->zoom;
	}
	else if (keysym == KEY_LEFT)
	{
		mlx->c_real_beg -= 0.1 / mlx->zoom;
		mlx->c_real_end -= 0.1 / mlx->zoom;
	}
	else if (keysym == KEY_RIGHT)
	{
		mlx->c_real_beg += 0.1 / mlx->zoom;
		mlx->c_real_end += 0.1 / mlx->zoom;
	}
	return (0);
}

int	keypress_bonus(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx->window = NULL;
	}
	else
		key_move(keysym, mlx);
	return (0);
}

static void	move_in(t_mlx *mlx, long double move_real, long double move_ima)
{

	if (move_real >= 0)
		mlx->c_real_beg = (mlx->c_real_beg + move_real * 0.6);
	else if (move_real < 0)
		mlx->c_real_end = (mlx->c_real_end + move_real * 0.6);
	if (move_ima >= 0)
		mlx->c_ima_end = (mlx->c_ima_end + move_ima * 0.6);
	else if (move_ima < 0)
		mlx->c_ima_beg = (mlx->c_ima_beg + move_ima * 0.6);
}

static void	move_out(t_mlx *mlx, long double move_real, long double move_ima)
{

	if (move_real >= 0)
		mlx->c_real_beg = (mlx->c_real_beg - move_real * 0.6);
	else if (move_real < 0)
		mlx->c_real_end = (mlx->c_real_end - move_real * 0.6);
	if (move_ima >= 0)
		mlx->c_ima_end = (mlx->c_ima_end - move_ima * 0.6);
	else if (move_ima < 0)
		mlx->c_ima_beg = (mlx->c_ima_beg - move_ima * 0.6);
}
// TODO: Insert new zoom algorithm
// TODO: zoom out should go back to the original position
// TODO: Norminette
int	zoom_press_bonus(int keysym, int x, int y, t_mlx *mlx)
{
	long double	step_real;
	long double	step_ima;
	long double	move_real;
	long double	move_ima;

	step_real = (mlx->c_real_end - mlx->c_real_beg) / mlx->win_length;
	step_ima = (mlx->c_ima_beg - mlx->c_ima_end) / mlx->win_height;
	move_real = (x - mlx->win_length / 2) * step_real;
	move_ima = (mlx->win_height / 2 - y) * step_ima;
	if (keysym == 4)
	{
		mlx->zoom *= 1.1;
		move_in(mlx, move_real, move_ima);
	}
	else if (keysym == 5 && mlx->zoom > 1)
	{
		mlx->zoom /= 1.1;
		move_out(mlx, move_real, move_ima);
	}
	return (0);
}
