/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:53:12 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:42:09 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			while (str[i] != ' ' && str[i] != '-' 
				&& str[i] != '+' && str[i] != '\0')
				i++;
			i++;
		}
		else
		{
			while (str[i] != ' ' && str[i] != '-' 
				&& str[i] != '+' && str[i] != '\0')
				i++;
			i++;
		}
	}
	return (str);
}

int	main(void)
{
	char	palabra[] = "ola, tu,do be.m? 42palavras quarenta-e-duas; cinquenta+e+um";

	printf("\n%s", palabra);
	ft_strcapitalize(palabra);
	printf("\n%s", palabra);
	return (0);
}
