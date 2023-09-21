/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:02:01 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/06 17:33:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j == 0 && str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
			j++;
		}
		else if (j != 0 && str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		else if (j == 0 && ((str[i] >= '0' && str[i] <= '9') || 
				(str[i] >= 'A' && str[i] <= 'Z')))
			j++;
		else if ((str[i] >= 91 && str[i] <= 96) || str[i] > 122 || 
			(str[i] >= 32 && str[i] <= 47) || 
			(str[i] >= 58 && str[i] <= 64))
			j = 0;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[100] = "hEllo World! 42piscine+hsab";
	char	*str1;

	str1 = ft_strcapitalize(str);
	printf("%s\n", str1);
}*/
