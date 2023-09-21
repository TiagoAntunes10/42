/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:05:18 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/02 15:20:43 by mmaia-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0' )
	{
		if (str[a] < 97 || str[a] > 122)
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

	m  = "marcelo";
	ft_str_is_lowercase(m);
	printf("%d\n", ft_str_is_lowercase(m));
}
*/
