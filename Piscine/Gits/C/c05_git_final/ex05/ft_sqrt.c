/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:26:02 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 08:50:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);
int	my_sqrt(int nb, int guess, int last_guess);

int	ft_sqrt(int nb)
{
	int	i;
	int	value;

	i = 1;
	if (nb <= 0 || nb > 2147395600)
		return (0);
	else
	{
		value = my_sqrt(nb, i, nb);
		return (value);
	}
}

int	my_sqrt(int nb, int guess, int last_guess)
{
	if (guess * guess != nb && guess == last_guess)
		return (0);
	else if (guess * guess != nb)
		return (my_sqrt(nb, (guess + nb / guess) / 2, guess));
	else if (guess * guess == nb)
		return (guess);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_sqrt(25));
}*/
