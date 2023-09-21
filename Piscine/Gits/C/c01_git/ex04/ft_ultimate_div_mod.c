/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:20:58 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/27 16:26:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	d;
	int	r;

	d = *a / *b;
	r = *a % *b;
	*a = d;
	*b = r;
}

/*int	main(void)
{
	int	*a;
	int	*b;
	int	c;
	int	d;

	c = 5;
	d = 5;
	a = &c;
	b = &d;
	ft_ultimate_div_mod(a, b);
	printf("div: %d\n", *a);
	printf("div: %d\n", *b);
}*/
