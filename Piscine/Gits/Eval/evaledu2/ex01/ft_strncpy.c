/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-abre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:18:59 by ede-abre          #+#    #+#             */
/*   Updated: 2023/09/10 16:35:57 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strncpy(char *dest,	char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int     main(void)
{
        char    *fuente;
        char    destino[50];

        fuente = "Esto es una prueba final";
        printf("Antes  destino:%s\n", destino);
        ft_strncpy(destino, fuente, 6);
        printf("\nAhora en destino dice : %s\n", destino);
        return (0);
}
