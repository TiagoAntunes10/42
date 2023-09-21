/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:23:48 by ade-alme          #+#    #+#             */
/*   Updated: 2023/09/09 16:25:48 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d;
	unsigned int	s;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	d = j;
	s = ft_strlen(src);
	if (size == 0 || size <= d)
		return (s + size);
	while (src[i] != '\0' && i < size - d - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d + s);
}

int	main(void)
{
	char	src[] = "Go Piscine";
	char	dest[] = "go ";
	printf("%i \n", ft_strlcat(dest, src, 2));
	printf("%s \n", dest);
}

