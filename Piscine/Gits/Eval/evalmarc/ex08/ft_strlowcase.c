/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 07:53:50 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/04 08:02:18 by mmaia-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] > 64 && str[a] < 91)
		{
			str[a] = str[a] +32;
		}
		a++;
	}
	return (str);
}
/*
int	main(void)
{
	char	m[20] = "MARCELO";

	ft_strlowcase(m);
	printf("%s\n", ft_strlowcase(m));
}
*/
