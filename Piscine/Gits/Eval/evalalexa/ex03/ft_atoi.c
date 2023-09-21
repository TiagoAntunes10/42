/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:45:54 by aneiva-d          #+#    #+#             */
/*   Updated: 2023/09/08 09:33:54 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	nop;

	nb = 0;
	nop = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			nop = nop * 1;
		else if (str[i] == '-')
			nop = nop * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	nb = nb * nop;
	return (nb);
}

#include <stdio.h> 
int	main(void)
{
	char	string[] = "  ---+--+1234ab567";
	printf("%i", ft_atoi(string));
	return (0);
}
