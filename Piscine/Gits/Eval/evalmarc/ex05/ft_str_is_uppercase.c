/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:22:19 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/08 09:03:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	p;

	p = 0;
	if (str[p] == '\0')
	{
		return (1);
	}
	while (str[p] != '\0')
	{
		if (!(str[p] >= 'A' && str[p] <= 'Z'))
		{
			return (0);
		}
		p++;
	}
	return (1);
}


int	main(void)
{
	char	*m;

	m  = "MAdfsRCELO";
	ft_str_is_uppercase(m);
	printf("%d\n", ft_str_is_uppercase(m));
}
