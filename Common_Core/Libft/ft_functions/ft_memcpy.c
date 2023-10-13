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

static unsigned char	*ft_cpy(unsigned char *dest, 
							unsigned char const *src, size_t n);

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned int			i;
	unsigned char			*cdest;
	unsigned char const		*csrc;

	if (dest == NULL && src == NULL)
		return (dest);
	cdest = (unsigned char *) dest;
	csrc = (unsigned char const *) src;
	i = 0;
	while (*csrc != '\0')
	{
		if (csrc == cdest)
		{
			csrc -= i;
			cdest = (unsigned char *) csrc;
			return (dest);
		}
		csrc++;
		i++;
	}
	csrc -= i;
	cdest = ft_cpy(cdest, csrc, n);
	return (dest);
}

static unsigned char	*ft_cpy(unsigned char *dest, 
							unsigned char const *src, size_t n)
{
	unsigned int		i;
	unsigned char		*cdest;
	unsigned char const	*csrc;

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
