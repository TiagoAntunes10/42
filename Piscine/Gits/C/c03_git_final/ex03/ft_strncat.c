/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:37:37 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/08 09:29:23 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (dest[j] != '\0')
		j++;
	i = 1;
	while (i <= nb && *src != '\0')
	{
		dest[j] = *src;
		j++;
		i++;
		src += 1;
	}
	dest[j] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*src;
	char	dest[100] = "Hello";
	char	dest2[100] = "Hello";

	src = " world";
	printf("%s\n", ft_strncat(dest, src, 10));
	printf("%s\n", strncat(dest2, src, 10));
}*/
