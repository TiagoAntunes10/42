/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-vei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:16:14 by avaz-vei          #+#    #+#             */
/*   Updated: 2023/09/07 19:10:42 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	k;
	unsigned int	j;

	k = 0;
	j = 0;
	while (dest[k] != '\0')
	{
		k++;
	}
	while (j < nb && src[j] != '\0')
	{
		dest[k + j] = src[j];
		j++;
	}
	dest[k + j] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>
int main()
{
char primeira[50] = "angg";
char segunda[] = "fogg";
char terceira[50] = "angg";
printf("%s",ft_strncat(primeira,segunda,10));
strncat(terceira,segunda, 10);
printf("%s",primeira);

}
