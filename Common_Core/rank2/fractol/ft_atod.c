/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:47:00 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/15 22:14:28 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_power(int base, int exp)
{
	int	result;

	if (exp > 0)
		result = base;
	else if (exp < 0)
		result = 1 / base;
	if (exp == 0)
		return (1);
	else if (exp > 0)
		result *= ft_power(base, exp - 1);
	else if (exp < 0)
		result *= ft_power(base, exp + 1);
	return (result);
}

// TODO: Test this function
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
			ld = ld + (*nb) * ft_power(10, - dec);
			dec++;
		}
		nb++;
	}
	return (ld);
}
