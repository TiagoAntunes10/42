/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:36:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 18:33:22 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}


#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dest1[] = "abacaxi";
	char dest2[] = "abacaxi";
	char src[] = "banana";
	printf("strcat: %s\n", strcat(dest1, src));
	printf("ft_strcat: %s\n", ft_strcat(dest2, src));
}

