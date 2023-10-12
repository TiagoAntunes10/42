/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:02:15 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/03 09:25:03 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	unsigned int	i;

	i = 1;
	while (*src != '\0')
	{
		if (i < size)
		{
			*dest = *src;
			dest += 1;
		}
		src += 1;
		i++;
	}
	*dest = 0;
	return ((i - 1));
}
