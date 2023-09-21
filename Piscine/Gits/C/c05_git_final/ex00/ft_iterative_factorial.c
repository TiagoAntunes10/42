/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:27:05 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 11:26:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	value;

	value = 1;
	if (nb < 0)
		return (0);
	while (nb >= 1)
	{
		value *= nb;
		nb--;
	}
	return (value);
}

/*#include <stdio.h>
int main(void)
{
	int nb;
    
	nb = 0;
	printf("%d\n", ft_iterative_factorial(nb));
}*/
