/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:47:00 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/25 12:35:24 by tialbert         ###   ########.fr       */
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

static int	check_num(char *str)
{
	int	com;

	com = 0;
	while (*str != 0)
	{
		if (*str == '.')
			com++;
		else if (ft_isdigit(*str) == 0)
			return (1);	
		if (com > 1)
			return (1);	
		str++;
	}
	return (0);
}

long double	ft_atod(char *str, int neg)
{
	long double	ld;
	int			dec;

	if (check_num(str) == 1)
		errno = -1;
	dec = 0;
	ld = 0;
	while (*str != 0)
	{
		if (*str == '.' || *str == ',')
			dec++;
		else if (dec == 0)
			ld = ld * 10 + (*str) - 48;
		else if (dec >= 1)
		{
			ld += ((*str) - 48) * pow(10, -dec);
			dec++;
		}
		str++;
	}
	if (neg == 1)
		ld *= -1;
	return (ld);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%Lf", ft_atod("37438473.848738", 1));
// }
