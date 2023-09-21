/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-vei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:27:24 by avaz-vei          #+#    #+#             */
/*   Updated: 2023/09/07 19:13:27 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	if (size < i)
		return (i);
}

#include <stdio.h>
int main()
{
	printf("%d",ft_strlcat("as","bc",1));
}
