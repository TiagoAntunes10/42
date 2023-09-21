/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:57:06 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 18:34:04 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0' && j < nb)
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
	printf("strncat: %s\n", strncat(dest1, src, 4));
	printf("ft_strncat: %s\n", ft_strncat(dest2, src, 4));
}

