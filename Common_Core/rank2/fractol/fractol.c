/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:20 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/04 22:05:55 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: Add a condition in Makefile to build the minilibx library
int	main(int argc, char **argv)
{
	if (argc < 2)
		show_options(argc);
	if (ft_strncmp(argv[1], "julia", 5) == 0 ||
		ft_strncmp(argv[1], "-j", 2) == 0)
		julia(argv, argc);
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 ||
		ft_strncmp(argv[1], "-m", 2) == 0)
		mandel(argv, argc);
	else
		show_options(argc);
}
