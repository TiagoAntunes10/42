/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:47:00 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/18 14:09:39 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static int	ft_power(int base, int exp)
// {
// 	int	result;

// 	if (exp > 0)
// 		result = base;
// 	else if (exp < 0)
// 		result = 1 / base;
// 	if (exp == 0)
// 		return (1);
// 	else if (exp > 0)
// 		result *= ft_power(base, exp - 1);
// 	else if (exp < 0)
// 		result *= ft_power(base, exp + 1);
// 	return (result);
// }

long double	ft_atod(char *nb)
{
	long double	ld;
	int			dec;

	dec = 0;
	while (*nb != 0)
	{
		if (*nb == '.' || *nb == ',')
			dec++;
		else if (dec == 0)
			ld = ld * 10 + (*nb) - 48;
		else if (dec >= 1)
		{
			ld = ld + ((*nb) - 48) * pow(10, - dec);
			dec++;
		}
		nb++;
	}
	return (ld);
}

#include <stdio.h>
int main(void)
{
	printf("%Lf", ft_atod("374743.34389"));
}
