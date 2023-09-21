/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rneto-fo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:07:42 by rneto-fo          #+#    #+#             */
/*   Updated: 2023/09/08 08:34:52 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	uppercase(char i)
{
	return (i >= 'A' && i <= 'Z');
}

int	lowercase(char i)
{
	return (i >= 'a' && i <= 'z');
}

int	number(char i)
{
	return (i >= '0' && i <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	if (lowercase(str[0]))
		str[0] -= 32;
	while (str[j])
	{
		if (uppercase(str[j]))
			str[j] += 32;
		j++;
	}
	while (str[i] != '\0')
	{
		if (!uppercase(str[i - 1]) 
			&& !lowercase(str[i - 1]) && !number(str[i - 1]))
		{
			if (lowercase(str[i]))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "ola, tUDo beM? 42palaVras quareNta-e-duas; cinquenta+e+um";

	printf("%s\n", ft_strcapitalize(str));
}
