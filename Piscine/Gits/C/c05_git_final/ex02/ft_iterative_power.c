/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:21:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 08:45:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	value;

	i = 1;
	value = 1;
	if (power == 0 || (power == 0 && nb == 0))
		return (1);
	else if (power < 0)
		return (0);
	while (i <= power)
	{
		value *= nb;
		i++;
	}
	return (value);
}

/*#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_iterative_power(2, 3));
}*/
