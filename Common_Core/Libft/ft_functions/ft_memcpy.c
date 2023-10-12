/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:36:13 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:36:14 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char *dest, char const *src, size_t n);

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned int	i;
	char			*cdest;
	char const		*csrc;

	cdest = (char *) dest;
	csrc = (char const *) src;
	i = 0;
	while (*csrc != '\0')
	{
		if (csrc == cdest)
		{
			csrc -= i;
			cdest = (char *) csrc;
			return (cdest);
		}
		csrc++;
		i++;
	}
	csrc -= i;
	cdest = ft_cpy(cdest, csrc, n);
	return (cdest);
}

static char	*ft_cpy(char *dest, char const *src, size_t n)
{
	unsigned int	i;
	char			*cdest;
	char const		*csrc;

	cdest = dest;
	csrc = src;
	i = 0;
	if (csrc[i] != '\0')
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (cdest);
}
