/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:22:50 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 08:47:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	int	value;

	value = nb;
	if (power > 1)
		value *= ft_recursive_power(nb, power - 1);
	else if (power == 1)
		return (value);
	else if (power < 0)
		return (0);
	else
		return (1);
	return (value);
}

/*#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_recursive_power(2, 3));
}*/
