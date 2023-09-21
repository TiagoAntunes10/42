/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:03:57 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/08 09:05:49 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] <= 'z' && str[0] >= 'a')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' )
		{
			if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
			{
				if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
				{
					if (!(str[i - 1] <= '9' && str[i - 1] >= '0'))
					{
						str[i] -= 32;
					}
				}
			}
		}
		i++;
	}
	return (str);
}


int	main(void)
{
	char	m[] = "ola, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";

	ft_strcapitalize(m);
	printf("%s\n", ft_strcapitalize(m));
}

