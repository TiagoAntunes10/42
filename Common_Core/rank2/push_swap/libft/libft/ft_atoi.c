/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:50:15 by tialbert          #+#    #+#             */
/*   Updated: 2024/01/29 22:15:49 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int long	convert(char const *str);

int	ft_atoi(char const *str)
{
	int long	value;

	while (*str <= ' ' && (*str != '\a' && *str != '\b'))
		str++;
	if (*str == '-')
	{
		str++;
		value = convert(str);
		value = value * (-1);
	}
	else
		value = convert(str);
	return (value);
}

static int long	convert(char const *str)
{
	int long	value;

	value = 0;
	while (*str != '\0' && ft_isdigit(*str) > 0)
	{
		value *= 10;
		value += (*str - 48);
		str += 1;
	}
	if (value > 2147483647 || value < -2147483648)
		return (0);
	return (value);
}
