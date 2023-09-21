/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plereno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:42:30 by plereno-          #+#    #+#             */
/*   Updated: 2023/09/01 10:07:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>
int	main(void)
{
	int	c;
	int	d;
	int	e;
	int	f;

	c = 100;
	d = 5;
	ft_div_mod(c, d, &e, &f);
	printf("%d\n", e);
	printf("%d", f);
}

