/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:27:36 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:33:50 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

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

int	main(void)
{
	char	*fuente;
	char	destino[50];

	fuente = "Esto es una prueba final";
	printf("Antes  destino:%s\n", destino);
	ft_strcpy(destino, fuente);
	printf("\nAhora en destino dice : %s\n", destino);
	return (0);
}
