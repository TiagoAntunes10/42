/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:24:57 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/02 15:04:06 by mmaia-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0' )
	{
		if (str[a] < 48 || str[a] > 57)
		{
			return (0);
		}
		a++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*m;

	m = "0";
	ft_str_is_numeric(m);
	printf("%d\n", ft_str_is_numeric(m));
}
*/
