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
int	check(char *str);
int	count_neg(char *str);
int	convert(char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	value;

	i = check(str);
	if (i == -1)
		return (0);
	while (*str <= 32)
		str += 1;
	i = count_neg(str);
	if (i == -1)
		return (0);
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			break ;
		str += 1;
	}
	value = convert(str);
	if ((i % 2) != 0)
		value = value * (-1);
	return (value);
}

int	check(char *str)
{
	while ((*str != '-' && *str != '+' && *str < '0') || *str > '9')
	{
		if ((*str != ' ' && *str > '\r') || *str < '\t')
			return (-1);
		str += 1;
	}
	return (1);
}

int	count_neg(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == 45)
			i++;
		else if (*str != '-' && *str != '+')
		{
			if (*str >= '0' && *str <= '9')
				break ;
			else
				return (-1);
		}
		str += 1;
	}
	return (i);
}

int	convert(char *str)
{
	int	value;

	value = 0;
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		value *= 10;
		value += (*str - 48);
		str += 1;
		if (*str < 48 || *str > 57)
			break ;
	}
	return (value);
}

/*#include <stdio.h>
int main(void)
{
	char	*str;

	str = "   ---+-+1203tghrt4567";
	printf("%d\n", ft_atoi(str));
}*/
