/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:23:07 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/09/03 11:46:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
int	strleng(char *stri)
{
	int	i;

	i = 0;
	while (stri[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	k;
	unsigned int	j;
	unsigned int	count;
	unsigned int	count2;

	j = 0;
	k = 0;
	while (dest[j])
		j++;
	count = j;
	count2 = strleng(src);
	if (size == 0 || size <= count)
		return (count2 + size);
	while (src[k] && (k < (size - count2 -1)))
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	dest[j] = '\0';
	return (count + count2);
}

int	main(void)
{
	unsigned int 	popota;
	popota = 6;
	char	st7[] = "eu sou ricaaaaa";
	char	st9[] = "eu sou ricaaaaa";
	char	st11[] = "eu sou ricaaaaa";
	char	st13[] = "eu sou ricaaaaa";
	char	st15[] = "eu sou ricaaaaa";
	char	st2[] = "eu sou111";
	char	st3[] = "f2u11";
	char	st4[] = "ae11";
	char	st5[] = "**";
	char	st6[] = "";

	printf("1 - %d\n", ft_strlcat(st7, st2, popota));
	printf("2 - %d\n", ft_strlcat(st9, st3, popota));
	printf("3 - %d\n", ft_strlcat(st11, st4, popota));
	printf("4 - %d\n", ft_strlcat(st13, st5, popota));
	printf("5 - %d\n", ft_strlcat(st15, st6, popota));
}
