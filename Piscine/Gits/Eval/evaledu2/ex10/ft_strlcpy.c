/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:10:06 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:47:47 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != 0 && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	char	dest[] = "Texto Original";
	char	src[] = "Este texto es el remplazo";
	int	size;

	printf("\n%s", dest);
	size = ft_strlcpy(dest,src,12);
	printf("\n%s", dest);
	printf("\nEl src tiene : %d caracteres", size);
	return(0);
}
