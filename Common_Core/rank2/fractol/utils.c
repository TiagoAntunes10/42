/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:35:27 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/14 16:04:17 by tialbert         ###   ########.fr       */
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

// TODO: Probably need to change ft_atoi to get long doubles
// TODO: Also need to protect this function for invalid arguments
void	get_c(char **argv, int argc, t_mlx *mlx)
{
	if (argc >= 3)
		mlx->c_real = ft_atoi(argv[3]);
	if (argc > 3)
		mlx->c_ima = ft_atoi(argv[4]);
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
