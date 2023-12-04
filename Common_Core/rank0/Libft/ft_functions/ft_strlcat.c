/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:48:35 by tialbert          #+#    #+#             */
/*   Updated: 2023/09/08 10:12:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cat(char *dest, char const *src, size_t size, unsigned int j);

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	unsigned int	j;

	j = 0;
	while (*dest != '\0')
	{
		j++;
		dest++;
	}
	if (j >= size)
		return (ft_strlen(src) + size);
	j = cat(dest, src, size, j);
	return (j);
}

static size_t	cat(char *dest, char const *src, size_t size, unsigned int j)
{
	while (*src != '\0')
	{
		if (j < size - 1)
		{
			*dest = *src;
			dest++;
		}
		src++;
		j++;
	}
	*dest = '\0';
	return (j);
}
