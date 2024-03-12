/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:35:27 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/18 15:01:07 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Finish handle_errors function with the necessary closes and frees
void	handle_errors(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->window != 0)
			mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_display(mlx->mlx);
		free(mlx);
	}
	exit(1);
}

t_mlx	*create_struct()
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->win_height = 600;
	mlx->win_length = 1067;
	mlx->line_lenght = 0;
	mlx->bits_per_pixel = 0;
	mlx->endian = 0;
	return (mlx);
}
