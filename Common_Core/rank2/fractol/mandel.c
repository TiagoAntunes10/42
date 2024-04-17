/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:59 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/14 16:05:34 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// If I have to include more colours, create another function that has
// all the if statements and returns a colour directly
// TODO: Maybe include a better way to calculate colours based on the counter
void	check_set(t_mlx *mlx, long double x, long double y)
{
	int			counter;
	int			max_ite;
	long double	r;
	long double	temp;
	
	counter = 0;
	r = 2;
	max_ite = 500;
	while ((x * x + y * y) < r * r && counter < max_ite)
	{
		temp = x * x - (y * y) + mlx->c_real + mlx->c_ima;
		y = 2 * x * y;
		x = temp;
		counter++;
	}
	if ((x * x + y * y) >= r * r || counter >= max_ite)  
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->backgr);
	else if (counter >= 0 && counter < max_ite * 3 / 4)  
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->foregr);
	else if (counter < max_ite && counter >= max_ite / 4)  
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color1);
	else if (counter < max_ite / 4 && counter >= max_ite * 2 / 4)  
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color2);
	else if (counter < max_ite * 2 / 4 && counter >= max_ite * 3 / 4)  
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color3);
}

static int	mandel_render_start(t_mlx *mlx)
{
	long double	z_x;
	long double	z_y;

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

void	mandel(char **argv, int argc)
{
	t_mlx	*mlx;
	
	mlx = open_window(argv);
	get_c(argv, argc, mlx);
	mlx_loop_hook(mlx->mlx, &mandel_render_start, mlx);
	mlx_mouse_hook (mlx->window, &zoom_press, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
	if (mlx->window == NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}
