/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diribeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:29:10 by diribeir          #+#    #+#             */
/*   Updated: 2023/09/14 11:17:10 by diribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i != nb)
	{
		if (i == 46340)
			return (0);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n",ft_sqrt(23));
}*/