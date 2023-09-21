/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:00:12 by erferrei          #+#    #+#             */
/*   Updated: 2023/09/06 18:48:46 by erferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	nb2;

	nb2 = nb - 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb2 > 0)
	{
		nb = nb * ft_recursive_factorial(nb2);
	}
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_factorial(3));
	return 0;
}*/
