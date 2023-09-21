/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:29:45 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/10 11:35:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);
int	prime_test(int nb, int i);
int	my_sqrt(int nb, int guess, int last_guess);

int	ft_find_next_prime(int nb)
{
	int	i;

	i = prime_test(nb, 5);
	if (i == 0)
		return (ft_find_next_prime(nb + 1));
	else
		return (nb);
}

int	prime_test(int nb, int i)
{
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else if (nb % i == 0 && nb % (i + 2) == 0)
		return (0);
	else if (my_sqrt(nb, 5, 0) <= i)
		return (1);
	else
		return (prime_test(nb, i + 4));
}

int	my_sqrt(int nb, int guess, int last_guess)
{
	if (guess * guess != nb && guess == last_guess)
		return (guess);
	else if (guess * guess != nb)
		return (my_sqrt(nb, (guess + nb / guess) / 2, guess));
	else if (guess * guess == nb)
		return (guess);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_find_next_prime(647463));
}*/
