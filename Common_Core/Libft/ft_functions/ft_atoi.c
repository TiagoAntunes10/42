/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:50:15 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/09 11:46:15 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	convert(char *str);

int	ft_atoi(char *str)
{
	int	value;

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

int	convert(char *str)
{
	int	value;

	value = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		value *= 10;
		value += (*str - 48);
		str += 1;
	}
	return (value);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char	*str;

	str = "1203";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));
}*/
