/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:11:24 by erferrei          #+#    #+#             */
/*   Updated: 2023/09/06 16:59:30 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	nb2;

	nb2 = nb - 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb2 > 0)
	{
		nb = nb * nb2;
		nb2--;
	}
	return (nb);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i;

	i = -2;
	printf("%d", ft_iterative_factorial(i));
}*/		
