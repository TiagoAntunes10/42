/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneiva-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:59:01 by aneiva-d          #+#    #+#             */
/*   Updated: 2023/09/08 09:41:43 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

int	ft_error(int *basev, char *base)
{
	int	i;

	i = 0;
	if (*basev <= 1)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] < 32 || base[i] > 126)
			return (1);
		if (base[i] == base[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	basev;
	int	check;
	int	i;
	int	nbrend[100];

	i = 0;
	basev = ft_strlen(base);
	check = ft_error(&basev, base);
	if (check == 1)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	while (nbr)
	{
		nbrend[i] = nbr % basev;
		nbr = nbr / basev;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &base[nbrend[i]], 1);
	}
}

int	main(void)
{
	int	i;
	char	base[] = "dasg";

	i = -2147483648;
	ft_putnbr_base(i, base);
}
