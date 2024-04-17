/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:50:01 by tialbert          #+#    #+#             */
/*   Updated: 2024/03/29 14:31:39 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_options(int argc)
{
	if (argc < 2)
	{
		ft_printf("Select options\n");
		ft_printf("julia or -j\nmandelbrot or -m\n");
		ft_printf("You can also modify the julia set by adding");
		ft_printf("2 float values (first value real component");
		ft_printf(", second value imaginary component)\n");
		exit(1);
	}
	ft_printf("Invalid option\n");
	ft_printf("julia or -j\nmandelbrot or -m\n");
	ft_printf("You can also modify the julia set by adding");
	ft_printf("2 float values (first value real component");
	ft_printf(", second value imaginary component)\n");
	exit(1);
}
