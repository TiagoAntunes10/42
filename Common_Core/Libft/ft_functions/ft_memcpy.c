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

static void	ft_cpy(unsigned char *dest, unsigned char const *src, size_t n);

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned char			*cdest;
	unsigned char const		*csrc;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char const *) src;
	if (cdest == NULL && csrc == NULL)
		return (dest);
	ft_cpy(cdest, csrc, n);
	return (dest);
}

static void	ft_cpy(unsigned char *dest, unsigned char const *src, size_t n)
{
	unsigned int		i;
	unsigned char		*cdest;
	unsigned char const	*csrc;

	cdest = dest;
	csrc = src;
	i = 0;
	while (i < n)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		i++;
	}
}
