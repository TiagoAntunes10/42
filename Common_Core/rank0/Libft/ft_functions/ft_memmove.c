/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:38:20 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:38:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned char			*cdest;
	unsigned char			*csrc;

	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	while (n--)
		cdest[n] = csrc[n];
	return (dest);
}
