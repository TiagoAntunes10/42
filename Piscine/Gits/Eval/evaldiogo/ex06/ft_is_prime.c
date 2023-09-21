/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diribeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:22:31 by diribeir          #+#    #+#             */
/*   Updated: 2023/09/14 13:24:28 by diribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_is_prime(3));
    printf("%d\n", ft_is_prime(1));
    printf("%d\n", ft_is_prime(2));
    printf("%d\n", ft_is_prime(0));
    printf("%d\n", ft_is_prime(7));
    printf("%d\n", ft_is_prime(2147483647));
    printf("%d\n", ft_is_prime(-2147483648));
    printf("%d\n", ft_is_prime(-1));
}*/