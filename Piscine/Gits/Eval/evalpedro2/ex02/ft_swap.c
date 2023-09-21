/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plereno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:43:39 by plereno-          #+#    #+#             */
/*   Updated: 2023/09/01 10:06:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 24;
	b = 42;
	printf("antes de correr a funcao temos a = %d", a);
	printf(" e b = %d\n", b);
	ft_swap(&a, &b);
	printf("depois de correr a funcao temos a = %d", a);
	printf(" e b = %d\n", b);
}

