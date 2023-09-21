/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:56:11 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 18:36:40 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0' && j + i + 1 < size)
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = '\0';
	while (*(src + j) != '\0')
		j++;
	if (size < i)
		return (size + j);
	return (i + j);
}


#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	dest1[] = "abacaxi";
	char	dest2[] = "abacaxi";
	char	*src = "banana";
	//printf("strlcat return: %i\n", strlcat(dest1, src, 5));
	//printf("dest1: %s\n\n", dest1);
	printf("ft_strlcat return: %i\n", ft_strlcat(dest2, src, 5));
	printf("dest2: %s\n", dest2);
}

