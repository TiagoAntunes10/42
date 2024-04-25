/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:35:27 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/25 15:18:52 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_c(char **argv, int argc, t_mlx *mlx)
{
	if (argc >= 3)
	{
		if (*argv[3] == '-')
			mlx->c_real = ft_atod(argv[3] + 1, 1);
		else
			mlx->c_real = ft_atod(argv[3], 0);
			
	}
	if (argc > 3)
	{
		if (*argv[4] == '-')
			mlx->c_ima = ft_atod(argv[4] + 1, 1);
		else
			mlx->c_ima = ft_atod(argv[4], 0);
			
	}
	if (errno == -1)
		handle_errors(mlx);
}

static int	*get_hex(int r, int g, int b)
{
	int	*hex;
	int	i;

	hex = malloc(sizeof(int) * 6);
	i = 0;
	while (i < 2)
	{
		hex[i] = r % 16;
		r /= 16;
		i++;
	}
	while (i < 4)
	{
		hex[i] = g % 16;
		g /= 16;
		i++;
	}
	while (i < 6)
	{
		hex[i] = b % 16;
		b /= 16;
		i++;
	}
	return (hex);
}

int	colours(int r, int g, int b)
{
	int	colour;
	int	i;
	int	*hex;

	if (r > 255 || g > 255 || b > 255)
	{
		errno = -1;
		return (0);
	}
	hex = get_hex(r, g, b);
	i = 0;
	while (i < 6)
	{
		colour = hex[i] * pow(16, i);
		i++;
	}
	free(hex);
	return (colour);
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
	mlx->zoom = 100;
	mlx->c_real = 1;
	mlx->c_ima = 0;
	mlx->backgr = 0x00000000;
	return (mlx);
}
