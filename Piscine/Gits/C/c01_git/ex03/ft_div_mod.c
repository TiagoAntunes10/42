/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:13:30 by tialbert          #+#    #+#             */
/*   Updated: 2023/08/27 16:20:06 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	d;
	int	m;

	a = 5;
	b = 10;
	div = &d;
	mod = &m;
	ft_div_mod(a, b, div, mod);
	printf("div: %d\n", *div);
	printf("mod: %d\n", *mod);
}*/
