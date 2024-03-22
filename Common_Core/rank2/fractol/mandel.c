/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:59 by tialbert          #+#    #+#             */
/*   Updated: 2024/03/22 14:49:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Add colors to the mlx struct (background, foreground and others)
// If I have to include more colours, create another function that has
// all the if statements and returns a colour directly
static void	check_set(t_mlx *mlx, float x, float y, float c)
{
	int		counter;
	int		max_ite;
	float	r;
	float	temp;
	
	counter = 0;
	r = 2;
	max_ite = 500;
	while ((x * x + y * y) < r && counter < max_ite)
	{
		temp = x * x - (y * y) + c;
		y = 2 * x * y;
		x = temp;
		counter++;
	}
	if ((x * x + y * y) >= r || counter >= max_ite)  
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

// TODO: Change the calculation of x and y to take into account the changes in zoom
// TODO: Add a zoom variable to the mlx struct
// TODO: Make mlx->x and mlx->y start at 0 position
// TODO: Add c constant to the mlx struct
static void	mandel_render_start(t_mlx *mlx)
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
			check_set(mlx, z_x, z_y, mlx->c);
			z_y += 1 / mlx->zoom * 10;
			mlx->y++;
		}
		z_x += 1 / mlx->zoom * 10;
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

static void	mandel_render_hook(t_mlx *mlx, int x, int y)
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
			check_set(mlx, z_x, z_y, mlx->c);
			z_y += 1 / mlx->zoom * 10;
			mlx->y++;
		}
		z_x += 1 / mlx->zoom * 10;
		mlx->x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

void	mandel(char **argv)
{
	mlx	t_mlx	*mlx;
	
	mlx = open_window();
	mlx->c = argv[2];
	mlx_loop_hook(mlx->mlx, &mandel_render_start, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &handle_keypress, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &handle_buttonpress, mlx);
	mlx_loop(mlx->mlx);
	if (mlx->window == NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}
