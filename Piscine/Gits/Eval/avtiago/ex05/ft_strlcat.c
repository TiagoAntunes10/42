/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:48:35 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/07 18:37:31 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	cat(char *dest, char *src, int size, int j);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (dest[j] != '\0')
	{
		if (j == size)
			dest[j] = '\0';
		j++;
	}
	if (j > size && dest[j] == '\0')
	{
		j = 0;
		while (src[j] != '\0')
			j++;
		return (j);
	}
	j = cat (dest, src, size, j);
	return (j);
}

int	cat(char *dest, char *src, int size, int j)
{
	while (*src != '\0')
	{
		if (j < size - 1)
			dest[j] = *src;
		else if (j == size - 1)
			dest[j] = '\0';
		src += 1;
		j++;
	}
	return (j);
}

#include <stdio.h>
int	main(void)
{
	char	dest[20] = "Hello";
	char	*src;
	int	n;

	src = " world";
	n = ft_strlcat(dest, src, 12);
	printf("%s\n%d\n", dest, n);
}
