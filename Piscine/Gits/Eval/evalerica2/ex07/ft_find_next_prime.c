/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:53:45 by erferrei          #+#    #+#             */
/*   Updated: 2023/09/15 08:34:44 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb);
int	ft_sqrt(int nb);
int	aux_ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
	{
		return (nb);
	}
	if (ft_is_prime(nb) != 1)
	{
		return (ft_find_next_prime(nb + 1));
	}
	return (nb);
}

int	ft_is_prime(int nb)
{
	if (nb < 2 || (nb % 2 == 0 && nb > 2))
	{
		return (0);
	}
	if (aux_ft_is_prime(nb) == 0)
	{
		return (0);
	}
	else if (aux_ft_is_prime(nb) == 1)
	{
		return (1);
	}
	return (1);
}

int	aux_ft_is_prime(int nb)
{
	int	i;

	i = 3;
	while (i <= nb / i)
	{
		if (nb % i == 0 && i != nb)
		{
			return (0);
		}
		else if (nb % i == 0 && i == nb)
		{
			return (1);
		}
		i += 2;
	}
	return (1);
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(463425864));
}	
