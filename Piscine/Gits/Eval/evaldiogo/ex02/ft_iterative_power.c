/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diribeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:32:13 by diribeir          #+#    #+#             */
/*   Updated: 2023/09/15 08:42:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		result = nb * result;
		power--;
	}
	return (result);
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
}
