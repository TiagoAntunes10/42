/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:47:03 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/02 16:57:35 by mmaia-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0' )
	{
		if (str[a] > 96 && str[a] < 123)
		{
			str[a] = str[a] -32;
		}
		a++;
	}
	return (str);
}
/*
int	main(void)
{
	char	m[20] = "marcelo";

	ft_strupcase(m);
	printf("%s\n", ft_strupcase(m));
}
*/
