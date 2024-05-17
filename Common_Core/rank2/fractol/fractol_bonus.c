/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:20 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/15 21:42:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"
#include "./Include/bonus.h"

int	main(int argc, char **argv)
{
	errno = 0;
	if (argc < 2)
		show_options(argc);
	if (ft_strncmp(argv[1], "julia", 5) == 0
		|| ft_strncmp(argv[1], "-j", 2) == 0)
		julia_bonus(argv, argc);
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0
		|| ft_strncmp(argv[1], "-m", 2) == 0)
		mandel_bonus(argv, argc);
	else if (ft_strncmp(argv[1], "newton", 10) == 0
		|| ft_strncmp(argv[1], "-n", 2) == 0)
		newton(argv, argc);
	else
		show_options(argc);
}
