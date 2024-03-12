/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:34 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/21 21:20:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include "./libft/ft_printf.h"
#include "set.h"

typedef struct s_mlx {
	void	*mlx;
	void	*window;
	int		win_height;
	int		win_length;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		x;
	int		y;
	int		color;
}				t_mlx;

void	show_options(int argc);
void	handle_errors(t_mlx *mlx);
t_mlx	*create_struct();
t_mlx	*open_window();
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	push_img(t_mlx *mlx);

#endif
