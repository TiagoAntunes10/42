/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaia-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:04:45 by mmaia-de          #+#    #+#             */
/*   Updated: 2023/09/02 09:52:06 by mmaia-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Carvalho";
	char	src1[] = "Marceloo";
	char	dest[] = "Dinissso";
	char	dest1[] = "Maiaaaoo";
	
	printf("%s \n", ft_strcpy(dest, src));
	printf("%s", strcpy(dest1, src1));
	return (0);
}
*/
