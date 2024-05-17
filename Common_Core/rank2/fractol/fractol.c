/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:20 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/15 22:16:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

int	main(int argc, char **argv)
{
	errno = 0;
	if (argc < 2 || argc > 4)
		show_options(argc);
	if (ft_strncmp(argv[1], "julia", 5) == 0
		|| ft_strncmp(argv[1], "-j", 2) == 0)
		julia(argv, argc);
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0
		|| ft_strncmp(argv[1], "-m", 2) == 0)
		mandel(argv, argc);
	else
		show_options(argc);
}
