/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-vei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:16:14 by avaz-vei          #+#    #+#             */
/*   Updated: 2023/09/07 19:08:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	k;
	int	aux;

	i = 0;
	k = 0;
	aux = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	while (dest[k] != '\0')
	{
		k++;
	}
	while (aux < i)
	{
		dest[k + aux] = src[aux];
		aux++;
	}
	dest[k + aux] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>
int main()
{
char primeira[] = "Ola";
char segunda[] = "mundo";
char terceira[] = "Ola";
strcat(primeira,segunda);
printf("%s\n",primeira);
ft_strcat(terceira,segunda);
printf("%s",terceira);

}
